#ifndef \@BASE_H_INCLUDED
#define \@BASE_H_INCLUDED

#include <iostream>
#include <deque>
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
        NO_INCREMENTS = -2,
        NO_FINAL_STATE = -2,
    };

    enum        // Finac Indices, see s_finAc[]
    {
        R = 0,
        F,
        T,
        I
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
        private:
            size_t next();                  // obtain the next character
    };

    size_t          d_state;
    int             d_nextState;
    std::ostream   *d_out;
    Input           d_input;
    VectorInt       d_LAtail;
    int             d_finalInfo[2];         // 1st value: rule, 2nd value:
                                            //                  matchlength

    std::string     d_matched;              // matched characters
    bool            d_return;               // return after a rule's action 
    bool            d_more;                 // set to true by more()
    size_t          d_less;                 // # chars to rescan and to 
                                            // remove fm d_matched
$insert 4 declarations
    static size_t  const s_ranges[];
    static int     const s_finAc[][4];

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

    private:
        StartCondition d_currentStartCondition;

    public:
        std::string const &match() const;
        void set_debug(bool onOff);

    protected:
        \@Base(std::istream &in, std::ostream &out);

$insert debugDecl

            // members required by the standard interface
        void    ECHO() const;
        void    more();
        void    less(size_t nChars = 0);

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

    private:
        void incLAtails();

            // convenience functions, encapsulating expressions
        size_t tailLength(size_t ruleIdx) const;
        static bool incrementalTail(int const *finacInfo);
        static bool atFinalState(int finacInfo_F);
};

inline bool \@Base::atFinalState(int stateType)
{
    return stateType != NO_FINAL_STATE;
}

inline size_t \@Base::tailLength(size_t ruleIdx) const
{
    return d_LAtail[ruleIdx] == NO_INCREMENTS ? 0 : d_LAtail[ruleIdx];
}

inline bool \@Base::incrementalTail(int const *finacInfo)
{
    return finacInfo[T] != -1 && finacInfo[I];
}

inline std::string const &\@Base::match() const
{
    return d_matched;
}

inline void \@Base::ECHO() const
{
    *d_out << d_matched << '\n';
}

inline void \@Base::more()
{
    d_more = true;
}

inline void \@Base::less(size_t nChars)
{
    d_less = nChars;
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




