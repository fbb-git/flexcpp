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
    // The second value is the FLAG: see the scannerbase.h file
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

void \@Base::Input::reRead(size_t ch)
{
    if (ch < 0x100)
    {
$insert 8 debug.input "Input::reRead(" << ch << ")"
        if (ch == '\n')
            --d_lineNr;
        d_deque.push_front(ch);
    }
}

void \@Base::Input::reRead(std::string const &str, size_t fm)
{
    for (size_t idx = str.size(); idx-- > fm; )
        reRead(str[idx]);
}

\@Base::\@Base()
:
    d_startCondition(INITIAL),
    d_state(0),
    d_out(&std::cout),
    d_sawEOF(false),
    d_atBOL(true),
$insert tailCount
$insert debugInit
    d_dfaBase(s_dfa)
{}

\@Base::\@Base(std::istream &in, std::ostream &out)
:
    d_startCondition(INITIAL),
    d_state(0),
    d_out(&out),
    d_sawEOF(false),
    d_atBOL(true),
$insert tailCount
$insert debugInit
    d_input(in),
    d_dfaBase(s_dfa)
{}

$insert debugFunctions

void \@Base::redo(size_t nChars)
{
    size_t from = nChars >= length() ? 0 : length() - nChars;
    d_input.reRead(d_matched, from);
    d_matched.resize(from);
}

void \@Base::switchStreams(std::istream &iStream, std::ostream &out)
{
    *d_out << std::flush;
    d_out = &out;
    d_input = Input(iStream);
    d_filename = istreamName__();
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

std::string \@Base::istreamName__()
{
    std::string ret;
    std::ostringstream name;
    name << "<istream " << ++s_istreamNr << ">";
    ret = name.str();
    return ret;
}

void \@Base::pushStream(std::istream &iStream)
{
    pushStream(istreamName__(), &iStream, false);
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

    if (atFinalState())                     // FINAL state reached
        return ActionType__::MATCH;

    if (d_matched.size())
        return ActionType__::ECHO_FIRST;    // no match, echo the 1st char

    return range != s_rangeOfEOF ? 
                ActionType__::ECHO_CH 
            : 
                ActionType__::RETURN;
}

void \@Base::accept(size_t nChars)          // old name: less, now deprecated
{
    if (nChars < d_matched.size())
    {
        d_input.reRead(d_matched, nChars);
        d_matched.resize(nChars);
    }
}

  // The size of d_matched is determined:
  //    The current state is a known final state (as determined by 
  // inspectRFCs__(), just prior to calling matched__). 
  //    The contents of d_matched are reduced to d_final's size or (if set)
  // to the LOP-rule's tail size.
void \@Base::determineMatchedSize(FinData const &final)
{
    size_t length = final.matchLen;
    if (final.tailCount != UINT_MAX)
        length -= final.tailCount;

    d_input.reRead(d_matched, length);      // reread the tail section
    d_matched.resize(length);               // return what's left
}

  // At this point a rule has been matched.  The next character is not part of
  // the matched rule and is sent back to the input.  The final match length
  // is determined, the index of the matched rule is determined, and then
  // d_atBOL is updated. Finally the rule index is returned.
size_t \@Base::matched__(size_t ch)
{
$insert 4 debug.action "MATCH"
    d_input.reRead(ch);

    if (!d_atBOL)
        d_final.atBOL.rule = UINT_MAX;

    FinData &final = d_final.atBOL.rule == UINT_MAX ? 
                            d_final.notAtBOL
                        :
                            d_final.atBOL;

    determineMatchedSize(final);

    d_atBOL = *d_matched.rbegin() == '\n';

$insert 4 debug.action "match buffer contains `" << d_matched << "'"

    return final.rule;
}

size_t \@Base::getRange__(int ch)       // using int to prevent casts
{
    if (ch != AT_EOF)
        d_sawEOF = false;

    return ch == AT_EOF ? static_cast<size_t>(s_rangeOfEOF) : s_ranges[ch];
}

  // At this point d_nextState contains the next state and continuation is
  // possible. The just read char. is appended to d_match, and LOP counts
  // are updated.
void \@Base::continue__(int ch)
{
$insert 4 debug.action "CONTINUE, NEXT STATE: " << d_nextState
    d_state = d_nextState;

    if (ch != AT_EOF)
        d_matched += ch;
}

void \@Base::echoCh__(size_t ch)
{
$insert 4 debug.action "ECHO_CH" 
    std::cerr << static_cast<char>(ch);
    d_atBOL = ch == '\n';
}


   // At this point there is no continuation. The last character is
   // pushed back into the input stream as well as all but the first char. in
   // the buffer. The first char. in the buffer is echoed to stderr. 
   // If there isn't any 1st char yet then the current char doesn't fit any
   // rules and that char is then echoed
void \@Base::echoFirst__(size_t ch)
{
$insert 4 debug.action "ECHO_FIRST"
    d_input.reRead(ch);
    d_input.reRead(d_matched, 1);
    echoCh__(d_matched[0]);
}

    // Inspect all s_rfc elements associated with the current state
    //  If the s_rfc element has its COUNT flag set then set the 
    // d_tailCount[rule] value to the element's tailCount value, if it has its 
    // INCREMENT flag set then increment d_tailCount[rule]
    //  If neither was set set the d_tailCount[rule] to UINT_MAX
    // 
    // If the s_rfc element has its FINAL flag set then store the rule number
    // in d_final.second. If it has its FINAL + BOL flags set then store the
    // rule number in d_final.first
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
        size_t const *rfc = s_rfc[begin];
        size_t flag = rfc[FLAGS];
        size_t rule = rfc[RULE];

        if (flag & INCREMENT)
            ++d_tailCount[rule];
        else 
            d_tailCount[rule] = (flag & COUNT) ? rfc[ACCCOUNT] : UINT_MAX;

        if (flag & FINAL)
        {
            FinData &final = (flag & BOL) ? d_final.atBOL : d_final.notAtBOL;
            final = FinData { rule, d_matched.size(), d_tailCount[rule] };
        }
    }
}

void \@Base::reset__()
{
    d_final = Final { {UINT_MAX, UINT_MAX, UINT_MAX }, 
                      {UINT_MAX, UINT_MAX, UINT_MAX } };
    d_state = 0;
    d_return = true;

    if (!d_more)
        d_matched.clear();

    d_more = false;
}

int \@::executeAction__(size_t ruleIdx)
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
    preCode();

    while (true)
    {
        size_t ch = get__();                // fetch next char
        size_t range = getRange__(ch);      // determine the range

$insert 8 debugStep

        inspectRFCs__();                    // update d_tailCount values

        switch (actionType__(range))        // determine the action
        {
            case ActionType__::CONTINUE:
                continue__(ch);
            continue;

            case ActionType__::MATCH:
            {
                int ret = executeAction__(matched__(ch));
                if (return__())
                    return ret;
                break;
            }

            case ActionType__::ECHO_FIRST:
                echoFirst__(ch);
            break;

            case ActionType__::ECHO_CH:
                echoCh__(ch);
            break;

            case ActionType__::RETURN:
$insert 16 debug.action  "EOF_REACHED"
            return 0;

        } // switch

        reset__();
        preCode();
    } // while
}

$insert namespace-close
