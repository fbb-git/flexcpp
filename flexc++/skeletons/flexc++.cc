#include <fstream>
#include <sstream>
#include <stdexcept>

$insert class_ih

$insert namespace-open

    // s_ranges: use (unsigned) characters as index to obtain
    //           that character's range-number.
    //           The range for EOF is defined in a constant in the
    //           class header file
$insert ranges

    // s_dfa contains the rows of *all* DFAs ordered by start state.
    // The enum class StartCondition is defined in the baseclass header
    // INITIAL is always 0.
    // Each entry defines the row to transit to if the column's
    // character range was sensed. Row numbers are relative to the
    // used DFA and d_dfaBase is set to the first row of the subset to use.
    // The row's final two values are begin and end indices in
    // s_rfc[] (rule, flags and count), defining the state's rule details
$insert DFAs

    // The first value is the rule index
    // The second value is the FLAG:
    // 1: Final     4: Count        11: Final/BOL,Inc     
    // 2: Inc.      5: Final,Count  13: Final/BOL,Count
    // 3: Final,Inc 9: Final/BOL    
    // The third value is the LOP count value (valid for Count flags)
$insert RFCs

$insert DFAbases

size_t \@Base::s_istreamNr = 0;

$insert inputMembers

size_t \@Base::Input::next()
{
    size_t ch;

    if (d_deque.empty())                    // deque empty: next char fm
    {
        ch = d_in->get();                   // istream
        return *d_in ? ch : AT_EOF;
    }

    ch = d_deque.front();
    d_deque.pop_front();

    return ch;
}

void \@Base::Input::push_front(size_t ch)
{
    if (ch < 0x100)
    {
$insert 8 debug.input "Input::push_front(" << ch << ")"
        if (ch == '\n')
            --d_lineNr;
        d_deque.push_front(ch);
    }
}

void \@Base::Input::push_front(std::string const &str, size_t fm)
{
    for (size_t idx = str.size(); idx-- > fm; )
        push_front(str[idx]);
}

\@Base::\@Base()
:
    d_startCondition(INITIAL),
    d_state(0),
    d_out(&std::cout),
    d_sawEOF(false),
    d_atBOL(true),
$insert debugInit
    d_dfaBase(s_dfa)
{}

\@Base::\@Base(std::istream &in, std::ostream &out)
:
    d_startCondition(INITIAL),
    d_state(0),
    d_out(&out),
    d_sawEOF(false),
    d_input(in),
$insert debugInit
    d_dfaBase(s_dfa)
{}

$insert debugFunctions

void \@Base::redo(size_t nChars)
{
    size_t from = nChars >= length() ? 0 : length() - nChars;
    d_input.push_front(d_matched, from);
    d_matched.resize(from);
}

void \@Base::switchStreams(std::istream &iStream, std::ostream &out)
{
    *d_out << std::flush;
    d_out = &out;
    d_input = Input(iStream);
    d_filename = istreamName();
    d_sawEOF = false;
}

void \@Base::pushStream(std::string const &name,
                          std::istream *streamPtr, bool closeAtPop)
{
    if (d_streamStack.size() == s_maxSizeofStreamStack)
    {
        if (closeAtPop)
            delete streamPtr;
        throw std::length_error("Max stream stack size exceeded");
    }

    d_streamStack.push(StreamStruct{d_filename, d_input, closeAtPop});
    d_filename = name;
    d_input = Input(*streamPtr);
    d_sawEOF = false;
}

void \@Base::pushStream(std::string const &name)
{
    std::istream *streamPtr = new std::ifstream(name);
    if (!*streamPtr)
    {
        delete streamPtr;
        throw std::runtime_error("Cannot read " + name);
    }
    pushStream(name, streamPtr, true);
}

std::string \@Base::istreamName()
{
    std::string ret;
    std::ostringstream name;
    name << "<istream " << ++s_istreamNr << ">";
    ret = name.str();
    return ret;
}

void \@Base::pushStream(std::istream &iStream)
{
    pushStream(istreamName(), &iStream, false);
}

bool \@Base::popStream()
{
    if (d_streamStack.empty())
        return false;

    StreamStruct &top = d_streamStack.top();

    if (top.newIstream)
        d_input.destroy();

    d_input =   top.pushedInput;
    d_filename = top.pushedName;
    d_streamStack.pop();
    d_sawEOF = false;

    return true;
}

\@Base::ActionType__ \@Base::actionType__(size_t range)
{
    d_nextState = d_dfaBase[d_state][range];

    if (d_nextState != -1)                  // transition is possible
        return ActionType__::CONTINUE;

    if (!d_sawEOF && atFinalState(d_finalInfo.finac))   // FINAL state reached
    {
        d_sawEOF = range == s_rangeOfEOF;
        return ActionType__::MATCH;
    }


    if (range == s_rangeOfEOF)
        return ActionType__::EOF_REACHED;
    
    return ActionType__::ECHO_FIRST;        // no match, echo the 1st char
}

void \@Base::accept(size_t nChars)          // old name: less, now deprecated
{
    if (nChars < d_matched.size())
    {
        d_input.push_front(d_matched, nChars);
        d_matched.resize(nChars);
    }
}

  // If the current state's [F] value is:
  //    USE_LA_TAIL then d_LAtail[R] defines the LA tail.
  // Otherwise the current state's [F] value determines the LA tail. It may
  //    be 0, in which case d_matched is used as-is.
size_t \@Base::lookAheadTail(int const *finac) const
{
    size_t ruleIdx = finac[R];

    if (finac[F] == USE_LA_TAIL)
    {
$insert 8 debug.finac "Using (incremented) LA tail " << d_LAtail[ruleIdx]
        return d_LAtail[ruleIdx];
    }

$insert 4 debug.finac "Fixed tail = " << finac[F]
    return finac[F];
}

  // The size of d_matched is determined:
  //
  // The current state is a known final state (as determined by 
  // inspectFinac__(), just prior to calling matched__). 
  //
  // The contents of d_matched are reduced by the matched rule's LA size,
  // and the LA tail is returned to the input.
void \@Base::determineMatchedSize(int const *finac)
{
    size_t length = d_finalInfo.matchLen;   // length of the matched text
                                            
    if (size_t tail = lookAheadTail(finac)) // maybe reduce by LA's length
        length -=  tail;
        
    d_input.push_front(d_matched, length);  // push front the tail
    d_matched.resize(length);               // return what's left
}

  // At this point a rule has been matched.  The next character is not part of
  // the matched rule and is sent back to the input.  
  // The final match length is determined, and the index of the matched rule 
  // is returned.
int \@Base::matched__(size_t ch)
{
$insert 4 debug.action "MATCH"
    d_input.push_front(ch);

    int const *finac = d_finalInfo.finac;   // final info for this state
    
    determineMatchedSize(finac);
$insert 4 debug.action "match buffer contains `" << d_matched << "'"

    return finac[R];
}

size_t \@Base::getRange__(size_t ch)
{
    if (static_cast<int>(ch) != AT_EOF)
        d_sawEOF = false;

    return ch == AT_EOF? s_rangeOfEOF : s_ranges[ch];
}

void \@Base::incLAtails()
{
    for
    (
        auto iter = d_LAtail.begin(), end = d_LAtail.end(); 
            iter != end; 
                ++iter
    )
    {
        if (*iter != NO_LA_TAIL)
        {
            ++*iter;
$insert 12 debug.finac "LA tail for rule " << (iter - d_LAtail.begin()) +
$insert 12 debug.finac " now: " << *iter
        }
    }
}

  // At this point d_nextState contains the next state and continuation is
  // possible. The just read char. is appended to d_match, and LA tail 
  // counts are incremented.
void \@Base::continue__(size_t ch)
{
$insert 4 debug.action "CONTINUE, NEW STATE: " << d_nextState
    d_state = d_nextState;

    switch (ch)
    {
        case AT_EOF:
        break;

        default:
            d_matched += ch;
            incLAtails();
        break;
    }
}

   // At this point there is no continuation. The last character is
   // pushed back into the input stream as well as all but the first char. in
   // the buffer. The first char. in the buffer is echoed to stderr. 
   // If there isn't any 1st char yet then the current char doesn't fit any
   // rules and that char is then echoed
void \@Base::echoFirst__(size_t ch)
{
$insert 4 debug.action "ECHO_FIRST"
    if (d_matched.empty())          // no match possible: echo ch itself
        std::cout << ch;
    else                            // echo the 1st matched char, push_front
    {                               // the rest
        d_input.push_front(ch);
        d_input.push_front(d_matched, 1);
        std::cerr << (ch = d_matched[0]);
    }
}

    // Inspect all s_rfc elements associated with the current state
    // 
    // If the current state is a final state for a rule ([F] != NO_FINAL_STATE
    // then store the address of the current s_finAc element and the current 
    // buffer length in d_finalInfo.
    //
    // If the current state defines an incremental tail ([I] == 1) then 
    // store the [T] value at d_LAtail[R]
void \@Base::inspectRFCs__()
{
    for 
    (
        size_t begin = d_dfaBase[d_state][s_finacIdx], 
                 end = d_dfaBase[d_state][s_finacIdx + 1];
            begin != end;
                ++begin
    )
    {
        int const *finac = s_finAc[begin];

            // If the current state is a rule's final state then store 
            // the finac info and the current buffer length in d_finalInfo.
        if (atFinalState(finac))
        {
$insert 12 debug.finac "Setting fixed LAtail [" << finac[R] << "] to " +
$insert 12 debug.finac finac[F]
            d_finalInfo = 
                {
                    finac,              // store the finac info's location
                    d_matched.size()    // and the match length
                };
        }

        if (finac[I])                   // incremental tail
        {
            if (d_LAtail[ finac[R] ] == NO_LA_TAIL) // set unless already set
            {
$insert 16 debug.finac "Setting LAtail [" << finac[R] << "] to " +
$insert 16 debug.finac finac[T] << ", incrementing"
                d_LAtail[ finac[R] ] = finac[T];
            }
        }
    }   
}

void \@Base::reset__()
{
    d_state = 0;
    d_return = true;

    if (!d_more)
        d_matched.clear();

    d_more = false;
    d_finalInfo = {0, };
    d_LAtail = VectorInt(s_nRules, NO_LA_TAIL);
}

int \@::executeAction__(int ruleIdx)
{
$insert 4 debug.action  "Executing actions of rule " << ruleIdx
    switch (ruleIdx)
    {
$insert 8 actions
    }
$insert 4 debug.action "Rule " << ruleIdx << " did not do 'return'"
    noReturn__();
    return 0;
}

int \@::lex__()
{
    reset__();
    preCode__();

    while (true)
    {
        size_t ch = get__();                // fetch next char
        size_t range = getRange__(ch);      // determine the range

$insert 8 debugStep

        inspectFinac__();

        switch (actionType__(range))        // determine the action
        {
            case ActionType__::CONTINUE:
                continue__(ch);
            break;

            case ActionType__::ECHO_FIRST:
                echoFirst__(ch);
                reset__();                      // fresh start 
                preCode__();
            break;

            case ActionType__::EOF_REACHED:
$insert 16 debug.action  "EOF_REACHED"
            return 0;

            case ActionType__::MATCH:
            {
                int ret = executeAction__(matched__(ch));
                if (return__())
                    return ret;
                reset__();
                preCode__();
                continue;
            }
        } // switch
    } // while
}

$insert namespace-close
