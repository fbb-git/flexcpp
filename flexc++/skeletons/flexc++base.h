#ifndef \@BASE_H_INCLUDED
#define \@BASE_H_INCLUDED

#include <iostream>
#include <deque>
#include <stack>
#include <string>
#include <vector>

$insert debugIncludes

$insert namespace-open

class \@Base
{
                // idx: rule, value: tail length (NO_INCREMENTS if no tail)
    typedef std::vector<int> VectorInt;

    enum 
    { 
        NO_LA_TAIL = -2,
        NO_FINAL_STATE = -2,
        USE_LA_TAIL = -1,
    };

    enum        // Finac Indices, see s_finAc[]
    {
        R = 0,
        F,
        T,
        I,
    };

    enum 
    {
        AT_BOL = -2,
        AT_EOF = -1
    };

protected:

    enum class ActionType__
    {
        CONTINUE,               // transition succeeded, go on
        ECHO_CH,                // echo ch itself (d_buffer empty)
        ECHO_FIRST,             // echo d_buffer[0], push back the rest
        EOF_REACHED,            // all input exhausted
        IGNORE_BOL,             // ignore a BOL range
        MATCH,                  // matched a rule
        REREAD,                 // return all but the 1st char to the input
    };

public:

    enum StartCondition {
$insert 8 startCondNames
    };


private:

    struct FinalInfo
    {
        int const *acccount;
        size_t matchLen;
    };

        // class Input encapsulates all input operations. 
        // Its member get() returns the next input character
    class Input
    {
        std::deque<unsigned char> d_deque;  // pending input chars
        std::istream *d_in;                 //  ptr for easy streamswitching
        size_t d_lineNr;                    // line count
        bool d_returnBOL;                   // initially true

        public:
            Input();
            Input(std::istream &iStream);
            size_t get();                   // the next range
            size_t lineNr() const;          
            void reRead(size_t ch);     // push back 'ch' (if <= 0x100)
                                            // push back string from idx 'fm'
            void reRead(std::string const &str, size_t fm = 1);

            void destroy();                 // delete dynamically allocated
                                            // d_in
        private:
            size_t next();                  // obtain the next character
    };

    struct StreamStruct
    {
        std::string pushedName;
        Input pushedInput;
        bool newIstream;
    };


    std::stack<StreamStruct>    d_streamStack;

    std::string     d_filename;             // name of the currently processed
    static size_t   s_istreamNr;            // file. With istreams it receives
                                            // the name "<istream #>", where
                                            // # is the sequence number of the 
                                            // istream (starting at 1)
    StartCondition  d_startCondition;
    size_t          d_state;
    int             d_nextState;
    std::ostream   *d_out;
    bool            d_sawEOF;               // saw EOF: ignore acccount
    Input           d_input;
    VectorInt       d_LAtail;
    FinalInfo       d_finalInfo;    

    std::vector<size_t> d_buffer;           // read buffer
    std::string     d_matched;              // matched characters
    bool            d_return;               // return after a rule's action 
    bool            d_more;                 // set to true by more()

protected:
    size_t d_beginStep__;
    size_t d_endStep__;
    size_t d_step__;

$insert 4 debugDecl

private:
    bool           d_startsAtBOL;           // the matched text starts at BOL

$insert 4 declarations
    static size_t  const s_ranges[];
    static int     const s_finAc[][4];
                                            // TODO: make configurable
    static size_t  const s_maxSizeofStreamStack = 10; 

public:

    bool                debug()     const;
    std::string const  &filename()  const;
    std::string const  &matched()   const;
    std::string const  &text()      const;

    size_t              length()    const;
    size_t              lineNr()    const;

    // deprecated, kept for backward compatibility
    size_t              leng()      const;
    size_t              lineno()    const;

    void                setDebug(bool onOff);
    void                switchStreams(std::istream &iStream);
    void                switchStreams(std::istream &iStream,
                                      std::ostream &oStream);
protected:

    \@Base();
    \@Base(std::istream &in, std::ostream &out);

    StartCondition  startCondition() const;   // current start condition
    bool            popStream();
    std::ostream   &out();
    void            begin(StartCondition startCondition);
    void            echo() const;

//    `less(n)' returns all but the first `n' characters of the current
// token back to the input stream, where they will be rescanned when the
// scanner looks for the next match.
//  So, it matches n of the characters in the input buffer, and so it accepts
//  n characters, rescanning the rest. I think 'less' is a highly confusing
// name. Use 'accept' instead, and avoid using 'less'.

    void            accept(size_t nChars = 0);      // former: less
    void            less(size_t nChars = 0);        // deprecated
    void            redo(size_t nChars = 0);        // rescan the last nChar
                                                    // characters, reducing
                                                    // length() by nChars
    void            more();
    void            push(size_t ch);                // push char to Input
    void            push(std::string const &txt);   // same: chars
    void            pushStream(std::istream &curStream);
    void            pushStream(std::string const &curName);
    void            setFilename(std::string const &name);
    void            setMatched(std::string const &text);

    static std::string istreamName();
        
        // members used by lex__(): they end in __ and should not be used
        // otherwise.

    ActionType__    actionType__(size_t range); // next action
    bool            return__();                 // 'return' from codeblock
    int             matched__(size_t ch);       // handles a matched rule
    size_t          getRange__(size_t ch);      // convert char to range
    size_t          get__();                    // next character
    size_t          state__() const;            // current state 
    void            continue__(size_t ch);      // handles a transition
    void            echoFirst__(size_t ch);     // handles unknown input
    void            ignoreBOL__();              // only if BOL's used
    void            inspectFinac__();           // set final/LA tails
    void            noReturn__();               // d_return to false
    void            pushFront__(size_t ch);     // return char to Input
    void            reset__();                  // prepare for new cycle

private:

    void pushStream(std::string const &name,
                      std::istream *streamPtr, bool closeAtPop);
    void incLAtails();
    void determineMatchedSize(int const *acccount);
    size_t lookAheadTail(int const *acccount) const;
    static bool atFinalState(int const *acccount);
};

inline void \@Base::Input::destroy()
{
    delete d_in;
}

inline size_t \@Base::Input::lineNr() const
{
    return d_lineNr;
}

inline std::ostream &\@Base::out()
{
    return *d_out;
}

inline void \@Base::push(size_t ch)
{
    d_input.reRead(ch);
}

inline void \@Base::setFilename(std::string const &name)
{
    d_filename = name;
}

inline void \@Base::setMatched(std::string const &text)
{
    d_matched = text;
}

inline void \@Base::switchStreams(std::istream &iStream)
{
    switchStreams(iStream, *d_out);
}

inline bool \@Base::atFinalState(int const *acccount)
{
    return acccount && acccount[F] != NO_FINAL_STATE;
}

inline std::string const &\@Base::matched() const
{
    return d_matched;
}

inline \@Base::StartCondition \@Base::startCondition() const
{
    return d_startCondition;
}

inline std::string const &\@Base::filename() const
{
    return d_filename;
}

inline std::string const &\@Base::text() const
{
    return d_matched;
}

inline void \@Base::echo() const
{
    *d_out << d_matched;
}

inline size_t \@Base::length() const
{
    return d_matched.size();
}

inline size_t \@Base::lineNr() const
{
    return d_input.lineNr();
}

inline size_t \@Base::leng() const
{
    return d_matched.size();
}

inline size_t \@Base::lineno() const
{
    return d_input.lineNr();
}

inline void \@Base::more()
{
    d_more = true;
}

inline void \@Base::less(size_t nChars)
{
    accept(nChars);
}

inline void \@Base::begin(StartCondition startCondition)
{
    d_dfaBase = s_dfaBase[d_startCondition = startCondition];
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




