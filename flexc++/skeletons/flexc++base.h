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

    struct FinalInfo
    {
        int const *finac;
        size_t matchLen;
    };

        // class Input encapsulates all input operations. 
        // The member get returns the next input character
    enum InputSpecials
    {
        AT_BOL = -2,
        AT_EOF = -1
    };

    class Input
    {
        std::deque<unsigned char> d_deque;  // pending input chars
        std::istream *d_in;                 //  ptr for easy streamswitching
        bool d_returnBOL;                   // initially true

        public:
            Input(std::istream &iStream);
            size_t get();                   // the next range
            void push_front(size_t ch);     // push back 'ch' (if <= 0x100)
                                            // push back string from idx 'fm'
            void push_front(std::string const &str, size_t fm = 1);

            void destroy();                 // delete dynamically allocated
                                            // d_in
        private:
            size_t next();                  // obtain the next character
    };

    struct StreamStruct
    {
        std::string curName;
        Input pushedInput;
        size_t pushedLineno;
        bool newIstream;
    };
        
    std::stack<StreamStruct>    d_streamStack;

    size_t          d_state;
    int             d_nextState;
    std::ostream   *d_out;
    Input           d_input;
    VectorInt       d_LAtail;
    FinalInfo       d_finalInfo;    

    std::string     d_matched;              // matched characters
    bool            d_return;               // return after a rule's action 
    bool            d_more;                 // set to true by more()
    size_t          d_lineno;               // number of lines read so far
                                            // initially 1, incremented at
                                            // each \n. 
$insert 4 debugDecl
$insert 4 declarations
    static size_t  const s_ranges[];
    static int     const s_finAc[][4];
                                            // TODO: make configurable
    static size_t  const s_maxSizeofStreamStack = 10; 

    protected:
        enum class ActionType__
        {
            CONTINUE,               // transition succeeded, go on
            ECHO_FIRST,             // no continuation from here
            EOF_REACHED,            // all input exhausted
            IGNORE_BOL,             // ignore a BOL range
            MATCH,                  // matched a rule
            PUSH_FRONT,             // return all chars to the input
        };


    public:
        enum StartCondition {
$insert 12 startCondNames
        };

    public:
        bool                debug()     const;
        size_t              leng()      const;
        size_t              lineno()    const;
        std::string const  &match()     const;
        std::string const  &text()      const;

        void                setDebug(bool onOff);
        void                switchStreams(std::istream &iStream);
        void                switchStreams(std::istream &iStream,
                                          std::ostream &oStream);

    protected:
        std::ostream &out();

        \@Base(std::istream &in, std::ostream &out);

            // members equal or similar to functions defined by flex
        void    echo() const;
        void    more();
        void    less(size_t nChars = 0);
        void    begin(StartCondition startCondition);

            // members used by the implementations: ending in __, so reserved
            // names
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
        void            pushFront__(size_t ch);     // return chars to Input
        void            reset__();                  // prepare for new cycle
        void            updateLineno__();           // update d_lineno

        void            pushStream__(std::string const &curName);
        void            pushStream__(std::istream &curStream);
        bool            popStream__();

    private:
        void pushStream__(std::string const &name,
                          std::istream *streamPtr, bool closeAtPop);
        void incLAtails();
        void determineMatchedSize(int const *finac);
        size_t lookAheadTail(int const *finac) const;
        static bool atFinalState(int const *finac);
};

inline void \@Base::Input::destroy()
{
    delete d_in;
}

inline std::ostream &\@Base::out()
{
    return *d_out;
}

inline void \@Base::switchStreams(std::istream &iStream)
{
    switchStreams(iStream, *d_out);
}

inline bool \@Base::atFinalState(int const *finac)
{
    return finac && finac[F] != NO_FINAL_STATE;
}

inline std::string const &\@Base::match() const
{
    return d_matched;
}

inline std::string const &\@Base::text() const
{
    return d_matched;
}

inline void \@Base::echo() const
{
    *d_out << d_matched;
}

inline size_t \@Base::leng() const
{
    return d_matched.size();
}

inline size_t \@Base::lineno() const
{
    return d_lineno;
}

inline void \@Base::more()
{
    d_more = true;
}

inline void \@Base::begin(StartCondition startCondition)
{
    d_dfaBase = s_dfaBase[startCondition];
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




