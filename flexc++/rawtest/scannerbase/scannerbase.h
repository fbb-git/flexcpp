#ifndef INCLUDED_SCANNERBASE_
#define INCLUDED_SCANNERBASE_

#include <string>
#include <unordered_map>
#include <queue>

class ScannerBase
{
    std::string d_match;
    std::queue<char> d_queue;
    bool d_bol;
    char d_char;        // most recently received character,
    size_t d_state;
    size_t d_nextState;

#include "../../tmp/bin/DECLARE"

    public:
        ScannerBase();
    protected:
        size_t next();
        bool lookup(size_t range);
        bool finalState() const;
        size_t ruleAction() const;
        void updateAcceptCounts();
        void reset();
        bool confirmExecute() const;

    private:
        void cleanup();

};
        
inline bool ScannerBase::finalState() const
{
    return d_dfa[d_state][s_finalIdx] != -1;
}

inline size_t ScannerBase::ruleAction() const
{
    return d_dfa[d_state][s_finalIdx];
}

#endif






