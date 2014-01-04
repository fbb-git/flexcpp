#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

$insert class_ih

$insert namespace-open

    // s_ranges__: use (unsigned) characters as index to obtain
    //           that character's range-number.
    //           The range for EOF is defined in a constant in the
    //           class header file
$insert ranges

    // s_dfa__ contains the rows of *all* DFAs ordered by start state.
    // The enum class StartCondition__ is defined in the baseclass header
    // INITIAL is always 0.
    // Each entry defines the row to transit to if the column's
    // character range was sensed. Row numbers are relative to the
    // used DFA and d_dfaBase__ is set to the first row of the subset to use.
    // The row's final two values are begin and end indices in
    // s_rf__[] (rule and flags), defining the state's rule details
$insert DFAs

    // The first value is the rule index
    // The second value is the FLAG: see the scannerbase.h file
    // 1: Final     9: Final/BOL    
$insert RFs

$insert DFAbases

size_t \@Base::s_istreamNr = 0;

$insert inputImplementation

\@Base::\@Base(std::istream &in, std::ostream &out)
:
    d_filename("-"),
    d_startCondition(StartCondition__::INITIAL),
    d_state(0),
    d_out(new std::ostream(out.rdbuf())),
    d_sawEOF(false),
    d_atBOL(true),
$insert interactiveInit
    d_dfaBase__(s_dfa__)
{}

void \@Base::switchStream__(std::istream &in, size_t lineNr)
{
    d_input.close();
    d_state = 0;
    d_input = Input(new std::istream(in.rdbuf()), lineNr);
    d_sawEOF = false;
    d_atBOL = true;
}

$ignoreInteractive BEGIN    this section is ignored by generator/filter.cc

\@Base::\@Base(std::string const &infilename, std::string const &outfilename)
:
    d_filename(infilename),
    d_startCondition(StartCondition__::INITIAL),
    d_state(0),
    d_out(outfilename == "-"    ? new std::ostream(std::cout.rdbuf()) :
          outfilename == ""     ? new std::ostream(std::cerr.rdbuf()) :
                                  new std::ofstream(outfilename)),
    d_sawEOF(false),
    d_atBOL(true),
    d_input(new std::ifstream(infilename)),
    d_dfaBase__(s_dfa__)
{}

void \@Base::switchStreams(std::istream &in, std::ostream &out)
{
    switchStream__(in, 1);
    switchOstream(out);
}

$ignoreInteractive END      end ignored section by generator/filter.cc

void \@Base::switchOstream(std::ostream &out)
{
    *d_out << std::flush;
    d_out.reset(new std::ostream(out.rdbuf()));
}

$insert debugFunctions

void \@Base::redo(size_t nChars)
{
    size_t from = nChars >= length() ? 0 : length() - nChars;
    d_input.reRead(d_matched, from);
    d_matched.resize(from);
}

void \@Base::switchOstream(std::string const &outfilename)
{
    *d_out << std::flush;
    d_out.reset(
            outfilename == "-"    ? new std::ostream(std::cout.rdbuf()) :
            outfilename == ""     ? new std::ostream(std::cerr.rdbuf()) :
                                    new std::ofstream(outfilename));
}

$ignoreInteractive BEGIN    this section is ignored by generator/filter.cc

void \@Base::switchIstream(std::string const &infilename)
{
    d_input.close();
    d_filename = infilename;
    d_input = Input(new std::ifstream(infilename));
    d_sawEOF = false;
    d_atBOL = true;
}

void \@Base::switchStreams(std::string const &infilename,
                           std::string const &outfilename)
{
    switchOstream(outfilename);
    switchIstream(infilename);
}

void \@Base::pushStream(std::istream  &istr)
{
    std::istream *streamPtr = new std::istream(istr.rdbuf());
    p_pushStream("(istream)", streamPtr);
}

void \@Base::pushStream(std::string const &name)
{
    std::istream *streamPtr = new std::ifstream(name);
    if (!*streamPtr)
    {
        delete streamPtr;
        throw std::runtime_error("Cannot read " + name);
    }
    p_pushStream(name, streamPtr);
}

$ignoreInteractive END      end ignored section by generator/filter.cc

void \@Base::p_pushStream(std::string const &name, std::istream *streamPtr)
{
    if (d_streamStack.size() == s_maxSizeofStreamStack__)
    {
        delete streamPtr;
        throw std::length_error("Max stream stack size exceeded");
    }

    d_streamStack.push_back(StreamStruct{d_filename, d_input});
    d_filename = name;
    d_input = Input(streamPtr);
    d_sawEOF = false;
    d_atBOL = true;
}


bool \@Base::popStream()
{
    d_input.close();

    if (d_streamStack.empty())
        return false;

    StreamStruct &top = d_streamStack.back();

    d_input =   top.pushedInput;
    d_filename = top.pushedName;
    d_streamStack.pop_back();
    d_sawEOF = false;

    return true;
}

\@Base::ActionType__ \@Base::actionType__(size_t range)
{
    d_nextState = d_dfaBase__[d_state][range];

    if (d_nextState != -1)                  // transition is possible
        return ActionType__::CONTINUE;

    if (atFinalState())                     // FINAL state reached
        return ActionType__::MATCH;

    if (d_matched.size())
        return ActionType__::ECHO_FIRST;    // no match, echo the 1st char

    return range != s_rangeOfEOF__ ? 
                ActionType__::ECHO_CH 
            : 
                ActionType__::RETURN;
}

void \@Base::accept(size_t nChars)          // old name: less
{
    if (nChars < d_matched.size())
    {
        d_input.reRead(d_matched, nChars);
        d_matched.resize(nChars);
    }
}

  // The size of d_matched is determined:
  //    The current state is a known final state (as determined by 
  // inspectRFs__(), just prior to calling matched__). 
  //    The contents of d_matched are reduced to d_final's size
void \@Base::determineMatchedSize(FinData const &final)
{
    size_t length = final.matchLen;

    d_input.reRead(d_matched, length);      // reread the tail section
    d_matched.resize(length);               // return what's left
}

  // At this point a rule has been matched.  The next character is not part of
  // the matched rule and is sent back to the input.  The final match length
  // is determined, the index of the matched rule is determined, and then
  // d_atBOL is updated. Finally the rule index is returned.
size_t \@Base::matched__(size_t ch)
{
$insert 4 debug "MATCH"
    d_input.reRead(ch);

    if (!d_atBOL)
        d_final.atBOL.rule = s_maxSize_t;

    FinData &final = d_final.atBOL.rule == s_maxSize_t ? 
                            d_final.notAtBOL
                        :
                            d_final.atBOL;

    determineMatchedSize(final);

    d_atBOL = *d_matched.rbegin() == '\n';

$insert 4 debug "match buffer contains `" << d_matched << "'"

    return final.rule;
}

size_t \@Base::getRange__(int ch)       // using int to prevent casts
{
    if (ch != AT_EOF)
        d_sawEOF = false;

$insert caseCheck
    return ch == AT_EOF ? static_cast<size_t>(s_rangeOfEOF__) : s_ranges__[ch];
}

  // At this point d_nextState contains the next state and continuation is
  // possible. The just read char. is appended to d_match, and LOP counts
  // are updated.
void \@Base::continue__(int ch)
{
$insert 4 debug "CONTINUE, NEXT STATE: " << d_nextState
    d_state = d_nextState;

    if (ch != AT_EOF)
        d_matched += ch;
}

void \@Base::echoCh__(size_t ch)
{
$insert 4 debug "ECHO_CH" 
    *d_out << static_cast<char>(ch);
    d_atBOL = ch == '\n';
}


   // At this point there is no continuation. The last character is
   // pushed back into the input stream as well as all but the first char. in
   // the buffer. The first char. in the buffer is echoed to stderr. 
   // If there isn't any 1st char yet then the current char doesn't fit any
   // rules and that char is then echoed
void \@Base::echoFirst__(size_t ch)
{
$insert 4 debug "ECHO_FIRST"
    d_input.reRead(ch);
    d_input.reRead(d_matched, 1);
    echoCh__(d_matched[0]);
}

    // Inspect all s_rf__ elements associated with the current state
    // If the s_rf__ element has its FINAL flag set then store the rule number
    // in d_final.second. If it has its FINAL + BOL flags set then store the
    // rule number in d_final.first
void \@Base::inspectRFs__()
{
    for 
    (
        size_t begin = d_dfaBase__[d_state][s_finacIdx__], 
                 end = d_dfaBase__[d_state][s_finacIdx__ + 1];
            begin != end;
                ++begin
    )
    {
        size_t const *rf = s_rf__[begin];
        size_t flag = rf[FLAGS];
        size_t rule = rf[RULE];

        if (flag & FINAL)
        {
            FinData &final = (flag & BOL) ? d_final.atBOL : d_final.notAtBOL;
            final = FinData { rule, d_matched.size() };
        }
    }
}

void \@Base::reset__()
{
    d_final = Final { {s_maxSize_t, s_maxSize_t }, 
                      {s_maxSize_t, s_maxSize_t } };
    d_state = 0;
    d_return = true;

    if (!d_more)
        d_matched.clear();

    d_more = false;
}

int \@::executeAction__(size_t ruleIdx)
try
{
$insert 4 debug.R  "Executing actions of rule " << ruleIdx
    switch (ruleIdx)
    {
$insert 8 actions
    }
$insert 4 debug "Rule " << ruleIdx << " did not do 'return'"
    noReturn__();
    return 0;
}
catch (Leave__ value)
{
    return static_cast<int>(value);
}

int \@::lex__()
{
    reset__();
    preCode();

    while (true)
    {
        size_t ch = get__();                // fetch next char
        size_t range = getRange__(ch);      // determine the range

        inspectRFs__();                     // determine final state for
                                            // bol/non-bol rules

        switch (actionType__(range))        // determine the action
        {
            case ActionType__::CONTINUE:
                continue__(ch);
            continue;

            case ActionType__::MATCH:
            {
                d_token__ = executeAction__(matched__(ch));
                if (return__())
                {
                    print();
                    postCode(PostEnum__::RETURN);
                    return d_token__;
                }
                break;
            }

            case ActionType__::ECHO_FIRST:
                echoFirst__(ch);
            break;

            case ActionType__::ECHO_CH:
                echoCh__(ch);
            break;

            case ActionType__::RETURN:
$insert 16 debug  "EOF_REACHED"
                if (!popStream())
                {
                     postCode(PostEnum__::END);
                     return 0;
                }
                postCode(PostEnum__::POP);
             continue;
        } // switch

        postCode(PostEnum__::WIP);

        reset__();
        preCode();
    } // while
}

void \@Base::print__() const
{
$insert 4 print
}

$insert interactiveLex

$insert namespace-close
