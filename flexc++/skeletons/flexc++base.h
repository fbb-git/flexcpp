#ifndef \@$BASE_H_INCLUDED
#define \@$BASE_H_INCLUDED

#include <limits>
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <memory>

$insert baseIncludes

$insert namespace-open

class \@Base
{
                // idx: rule, value: tail length (NO_INCREMENTS if no tail)
    typedef std::vector<int> VectorInt;

    static size_t const s_unavailable = std::numeric_limits<size_t>::max();

    enum 
    {
        AT_EOF = -1
    };

protected:
    enum Leave_
    {};

    enum class ActionType_
    {
        CONTINUE,               // transition succeeded, go on
        ECHO_CH,                // echo ch itself (d_matched empty)
        ECHO_FIRST,             // echo d_matched[0], push back the rest
        MATCH,                  // matched a rule
        RETURN,                 // no further continuation, lex returns 0.
    };

    enum class PostEnum_
    {
        END,                    // postCode called when lex_() ends 
        POP,                    // postCode called after switching files
        RETURN,                 // postCode called when lex_() returns
        WIP                     // postCode called when a non-returning rule
                                // was matched
    };

public:
$insert 4 startcondenum

private:
    struct FinalData
    {
        size_t rule;
        size_t length;
    };
    struct Final
    {
        FinalData std;
        FinalData bol;
    };

        // class Input encapsulates all input operations. 
        // Its member get() returns the next input character
$insert inputInterface

protected:
    struct StreamStruct
    {
        std::string pushedName;
        Input pushedInput;
    };

private:
    std::vector<StreamStruct>    d_streamStack;

    std::string     d_filename;             // name of the currently processed
    static size_t   s_istreamNr;            // file. With istreams it receives
                                            // the name "<istream #>", where
                                            // # is the sequence number of the 
                                            // istream (starting at 1)
    int             d_startCondition = 0;
    int             d_lopSC = 0;

    size_t          d_state = 0;
    int             d_nextState;
    std::shared_ptr<std::ostream> d_out;
    bool            d_atBOL = true;         // the matched text starts at BOL
    Final d_final;

                                            // only used interactively:
    std::istream *d_in;                     // points to the input stream
    std::shared_ptr<std::istringstream> d_line; // holds line fm d_in
    
    Input           d_input;
    std::string     d_matched;              // matched characters
    std::string     d_lopMatched;           // matched lop-rule characters 
    std::string::iterator d_lopIter;
    std::string::iterator d_lopTail;
    std::string::iterator d_lopEnd;

    size_t          d_lopPending;           // # pending input chars at lop1_
    bool            d_return;               // return after a rule's action 
    bool            d_more = false;         // set to true by more()

    size_t (\@Base::*d_get)() = &\@Base::getInput;

protected:
    std::istream   *d_in_;
    int d_token_;                          // returned by lex_

$insert 4 debugDecl

$insert 4 declarations
    static size_t  const s_ranges_[];
    static size_t  const s_rf_[][2];

public:
    \@Base(\@Base const &other)             = delete;
    \@Base &operator=(\@Base const &rhs)    = delete;

    bool                debug()     const;
    std::string const  &filename()  const;
    std::string const  &matched()   const;

    size_t              length()    const;
    size_t              lineNr()    const;

    void                setDebug(bool onOff);

    void                switchOstream(std::ostream &out);
    void                switchOstream(std::string const &outfilename);

$ignoreInteractive BEGIN    this section is ignored by generator/filter.cc

    void                switchStreams(std::istream &in,
                                      std::ostream &out = std::cout);

    void                switchIstream(std::string const &infilename);
    void                switchStreams(std::string const &infilename,
                                      std::string const &outfilename);

$ignoreInteractive END      end ignored section by generator/filter.cc

$insert interactiveDecl

protected:
    \@Base(std::istream &in, std::ostream &out);
$ignoreInteractive BEGIN    this section is ignored by generator/filter.cc
    \@Base(std::string const &infilename, std::string const &outfilename);
$ignoreInteractive END      end ignored section by generator/filter.cc
    ~\@Base();

    bool            popStream();
    std::ostream   &out();
    void            echo() const;
    void            leave(int retValue) const;

//    `accept(n)' returns all but the first `n' characters of the current
// token back to the input stream, where they will be rescanned when the
// scanner looks for the next match.
//  So, it matches n of the characters in the input buffer, and so it accepts
//  n characters, rescanning the rest. 
    void            accept(size_t nChars = 0);      // former: less
    void            redo(size_t nChars = 0);        // rescan the last nChar
                                                    // characters, reducing
                                                    // length() by nChars
    void            more();
    void            push(size_t ch);                // push char to Input
    void            push(std::string const &txt);   // same: chars

$ignoreInteractive BEGIN    this section is ignored by generator/filter.cc

    std::vector<StreamStruct> const &streamStack() const;

    void            pushStream(std::istream &curStream);
    void            pushStream(std::string const &curName);

$ignoreInteractive END      end ignored section by generator/filter.cc

    void            setFilename(std::string const &name);
    void            setMatched(std::string const &text);

    static std::string istreamName_();
        
        // members used by lex_(): they end in _ and should not be used
        // otherwise.

    ActionType_    actionType_(size_t range); // next action
    bool            return_();                 // 'return' from codeblock
    size_t          matched_(size_t ch);       // handles a matched rule
    size_t          getRange_(int ch);         // convert char to range
    size_t          get_();                    // next character
    size_t          state_() const;            // current state 
    void            continue_(int ch);         // handles a transition
    void            echoCh_(size_t ch);        // echoes ch, sets d_atBOL
    void            echoFirst_(size_t ch);     // handles unknown input
    void            updateFinals_();           // update a state's Final info
    void            noReturn_();               // d_return to false
    void            print_() const;            // optionally print token
    void            pushFront_(size_t ch);     // return char to Input
    void            reset_();                  // prepare for new cycle
                                                // next input stream:
    void            switchStream_(std::istream &in, size_t lineNr);   
    void            lopf_(size_t tail);        // matched fixed size tail
    void            lop1_(int lopSC);          // matched ab for a/b
    void            lop2_();                   // matches the LOP's b tail
    void            lop3_();                   // catch-all while matching b
    void            lop4_();                   // matches the LOP's a head

$insert startconddecl

    size_t getInput();
    size_t getLOP();
    void p_pushStream(std::string const &name, std::istream *streamPtr);
    void setMatchedSize(size_t length);
    bool knownFinalState();

    template <typename ReturnType, typename ArgType>
    static ReturnType constexpr as(ArgType value);
    static bool constexpr available(size_t value);
};

inline \@Base::~\@Base()
{
    d_input.close();
}

$insert startcondimpl

template <typename ReturnType, typename ArgType>
inline ReturnType constexpr \@Base::as(ArgType value)
{
    return static_cast<ReturnType>(value);
}

inline bool \@Base::knownFinalState()
{
    return (d_atBOL && available(d_final.bol.rule)) ||
           available(d_final.std.rule);
}

inline bool constexpr \@Base::available(size_t value)
{   
    return value != std::numeric_limits<size_t>::max();
}

inline std::ostream &\@Base::out()
{
    return *d_out;
}

inline void \@Base::push(size_t ch)
{
    d_input.reRead(ch);
}

inline void \@Base::push(std::string const &str)
{
    d_input.reRead(str, 0);
}

inline void \@Base::setFilename(std::string const &name)
{
    d_filename = name;
}

inline void \@Base::setMatched(std::string const &text)
{
    d_matched = text;
}

inline std::string const &\@Base::matched() const
{
    return d_matched;
}

inline std::string const &\@Base::filename() const
{
    return d_filename;
}

inline void \@Base::echo() const
{
    *d_out << d_matched;
}

inline size_t \@Base::length() const
{
    return d_matched.size();
}

inline void \@Base::leave(int retValue) const
{
    throw as<Leave_>(retValue);
}

inline size_t \@Base::lineNr() const
{
    return d_input.lineNr();
}

inline void \@Base::more()
{
    d_more = true;
}

inline size_t \@Base::state_() const
{
    return d_state;
}

inline size_t \@Base::get_()
{
    return (this->*d_get)();
}

inline size_t \@Base::getInput()
{
    return d_input.get();
}

inline bool \@Base::return_()
{
    return d_return;
}

inline void \@Base::noReturn_()
{
    d_return = false;
}

$insert namespace-close

#endif //  \@BASE_H_INCLUDED
