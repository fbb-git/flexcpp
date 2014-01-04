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

    static size_t const s_maxSize_t = std::numeric_limits<size_t>::max();

    enum        // RuleFlagsCount Indices, see s_rf__[]
    {
        RULE = 0,
        FLAGS,
        ACCCOUNT,
    };

    enum
    {
        FINAL = 1,
        INCREMENT = 2,
        COUNT = 4,
        BOL = 8
    };

    enum 
    {
        AT_EOF = -1
    };

protected:
    enum Leave__
    {};

    enum class ActionType__
    {
        CONTINUE,               // transition succeeded, go on
        ECHO_CH,                // echo ch itself (d_matched empty)
        ECHO_FIRST,             // echo d_matched[0], push back the rest
        MATCH,                  // matched a rule
        RETURN,                 // no further continuation, lex returns 0.
    };

    enum class PostEnum__
    {
        END,                    // postCode called when lex__() ends 
        POP,                    // postCode called after switching files
        RETURN,                 // postCode called when lex__() returns
        WIP                     // postCode called when a non-returning rule
                                // was matched
    };

public:
    enum class StartCondition__ {
$insert 8 startCondNames
    };

private:
    struct FinData            // Info about intermediate matched rules while
    {                           // traversing the DFA
        size_t rule;
        size_t matchLen;
    };

    struct Final
    {
        FinData atBOL;
        FinData notAtBOL;
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
    StartCondition__  d_startCondition;
    size_t          d_state;
    int             d_nextState;
    std::shared_ptr<std::ostream> d_out;
    bool            d_sawEOF;               // saw EOF
    bool            d_atBOL;                // the matched text starts at BOL
    Final d_final;                          // 1st for BOL rules
                                            
                                            // only used interactively:
    std::istream *d_in;                     // points to the input stream
    std::shared_ptr<std::istringstream> d_line; // holds line fm d_in
    
    Input           d_input;
    std::string     d_matched;              // matched characters
    bool            d_return;               // return after a rule's action 
    bool            d_more = false;         // set to true by more()

protected:
    std::istream   *d_in__;
    int d_token__;                          // returned by lex__

$insert 4 debugDecl

$insert 4 declarations
    static size_t  const s_ranges__[];
    static size_t  const s_rf__[][2];

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

    StartCondition__  startCondition() const;   // current start condition
    bool            popStream();
    std::ostream   &out();
    void            begin(StartCondition__ startCondition);
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

    static std::string istreamName__();
        
        // members used by lex__(): they end in __ and should not be used
        // otherwise.

    ActionType__    actionType__(size_t range); // next action
    bool            return__();                 // 'return' from codeblock
    size_t          matched__(size_t ch);       // handles a matched rule
    size_t          getRange__(int ch);         // convert char to range
    size_t          get__();                    // next character
    size_t          state__() const;            // current state 
    void            continue__(int ch);         // handles a transition
    void            echoCh__(size_t ch);        // echoes ch, sets d_atBOL
    void            echoFirst__(size_t ch);     // handles unknown input
    void            inspectFlags__();           // inspect the flags of a rule
    void            noReturn__();               // d_return to false
    void            print__() const;            // optionally print token
    void            pushFront__(size_t ch);     // return char to Input
    void            reset__();                  // prepare for new cycle
                                                // next input stream:
    void            switchStream__(std::istream &in, size_t lineNr);   

    //FBB
    // TO DO for lop handling:
    void            lopRedo__();                // pushback matched() but 1
    void            addLast__();                // add last char

private:
    void p_pushStream(std::string const &name, std::istream *streamPtr);
    void determineMatchedSize(FinData const &final);
    bool atFinalState();
};

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

inline bool \@Base::atFinalState()
{
    return d_final.notAtBOL.rule != s_maxSize_t || 
            (d_atBOL && d_final.atBOL.rule != s_maxSize_t);
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

inline \@Base::StartCondition__ \@Base::startCondition() const
{
    return d_startCondition;
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
    throw static_cast<Leave__>(retValue);
}

inline size_t \@Base::lineNr() const
{
    return d_input.lineNr();
}

inline void \@Base::more()
{
    d_more = true;
}

inline void \@Base::begin(StartCondition__ startCondition)
{
    d_dfaBase__ = 
        s_dfaBase__[static_cast<int>(d_startCondition = startCondition)];
}

inline size_t \@Base::state__() const
{
    return d_state;
}

inline size_t \@Base::get__()
{
    return d_input.get();
}

inline bool \@Base::return__()
{
    return d_return;
}

inline void \@Base::noReturn__()
{
    d_return = false;
}

$insert namespace-close

#endif //  \@BASE_H_INCLUDED




