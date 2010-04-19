#ifndef INCLUDED_SCANNERBASE_
#define INCLUDED_SCANNERBASE_

#include <string>
#include <unordered_map>
#include <deque>

class ScannerBase
{
    std::string d_match;
    std::deque<char> d_deque;
    bool d_bol;
    char d_char;                 // most recently received character,
    int d_state;
    int d_nextState;
    size_t d_range;

#include "../../tmp/bin/DECLARE"

    public:
        ScannerBase();
    protected:
        size_t next();
        void lookup(size_t range);
        bool finalState() const;
        size_t ruleAction() const;
        void updateAcceptCounts();
        void reset();
        bool callExecute() const;
        void nextState();
};
        
inline size_t ScannerBase::ruleAction() const
{
    return d_dfa[d_state][s_finalIdx];
}

#endif






