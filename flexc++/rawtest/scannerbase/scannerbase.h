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
        int  ruleIndex() const;
        void updateAcceptCounts();
        void reset();
        bool callExecute();
        void nextState();

    private:
        void saveLookahead();

        bool atEndOfRule();             // handles lookahead info
        bool atEOR() const;             // merely returns yes/no

        bool interactiveReturn() const;
        bool noTransition() const;
        bool transition() const;
        bool plainChar() const;
        bool atBOL() const;
};

inline bool ScannerBase::atBOL() const
{
    return d_range == s_rangeOfBOL;
}

inline bool ScannerBase::plainChar() const
{
    return d_range < s_rangeOfEOF;
}

inline bool ScannerBase::atEOR() const
{
    return ruleIndex() != -1;
}

inline bool ScannerBase::interactiveReturn() const
{
    return s_interactive && d_char == '\n';
}

inline bool ScannerBase::transition() const
{
    return d_nextState != -1;
}

inline bool ScannerBase::noTransition() const
{
    return not transition();
}

inline void ScannerBase::more()
{
    d_more = true;
}

inline std::string const &ScannerBase::match() const
{
    return d_match;
}
        
inline int ScannerBase::ruleIndex() const
{
    return d_dfa[d_state][s_finalIdx];
}

#endif






