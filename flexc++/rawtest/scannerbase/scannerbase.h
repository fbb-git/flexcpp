#ifndef INCLUDED_SCANNERBASE_
#define INCLUDED_SCANNERBASE_

#include <string>
#include <unordered_map>
#include <deque>

class ScannerBase
{
#include "../../tmp/bin/DECLARE"
    std::deque<char> d_deque;
    std::string d_match;
    size_t d_length;

    bool d_bol;
    char d_char;                 // most recently received character,
    int d_state;
    int d_nextState;
    size_t d_range;
    size_t d_lookaheadLength;
    bool d_more;

    public:
        ScannerBase();
        std::string const &match() const;
        void more();

    protected:
        size_t next();
        void lookup(size_t range);
        bool finalState();
        size_t ruleAction() const;
        void updateAcceptCounts();
        void reset();
        bool callExecute();
        void nextState();
};

inline void ScannerBase::more()
{
    d_more = true;
}

inline std::string const &ScannerBase::match() const
{
    return d_match;
}
        
inline size_t ScannerBase::ruleAction() const
{
    return d_dfa[d_state][s_finalIdx];
}

#endif






