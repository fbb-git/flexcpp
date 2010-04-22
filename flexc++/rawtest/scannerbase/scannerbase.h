#ifndef INCLUDED_SCANNERBASE_
#define INCLUDED_SCANNERBASE_

#include <string>
#include <unordered_map>
#include <deque>
#include <vector>

class ScannerBase
{
#include "../../tmp/bin/DECLARE"
    std::deque<char> d_deque;
    std::string d_match;

    bool d_bol;
    char d_char;                 // most recently received character,
    int d_state;
    int d_nextState;
    size_t d_range;
    int d_LAsize;
    bool d_more;
    int d_ruleIndex;

    public:
        ScannerBase();
        std::string const &match() const;

        void more();
        void less(size_t nChars);       // very strange name. Implemented as
        void retain(size_t nChars);     // a synonym of 'retain'
        int  input();
        void unput(char ch);

    protected:
            // used by Scanner::lex/execute
            //
        void lookup();
        size_t next();
        bool transition() const;
        void nextState();
        int  ruleIndex() const;
        void reset();
//        void updateAcceptCounts();
        bool callExecute();
        void charToMatchBuffer();
        bool interactiveReturn() const;
        bool atBOL() const;
        bool atEOF() const;
        bool streamPopped();
        void reRead();
        bool endOfRule();
        void notHandledChar() const;

    private:
        int selectRule() const;
        bool plainChar() const;

//        bool ruleAvailable() const;
//        bool noTransition() const;
//        bool rejectReturn();
//        void saveLookahead();
//
//        void updateCount(size_t rule);
};

inline void ScannerBase::reRead()
{
    return d_deque.push_front(d_char);
}

inline int ScannerBase::ruleIndex() const
{
    return d_ruleIndex;
}

inline bool ScannerBase::atBOL() const
{
    return d_range == s_rangeOfBOL;
}

inline bool ScannerBase::streamPopped()
{
    return false;
}

inline bool ScannerBase::atEOF() const
{
    return d_range == s_rangeOfEOF;
}

inline void ScannerBase::unput(char ch)
{
    d_deque.push_front(ch);
}

inline void ScannerBase::less(size_t nChars)
{
    retain(nChars);
}

// inline bool ScannerBase::ruleAvailable() const
// {
//     return d_ruleIndex != -1;
// }

inline bool ScannerBase::interactiveReturn() const
{
    return s_interactive && d_char == '\n';
}

inline bool ScannerBase::transition() const
{
    return d_nextState != -1;
}

// inline bool ScannerBase::noTransition() const
// {
//     return not transition();
// }

inline void ScannerBase::nextState() 
{
    d_state = d_nextState;
}

inline void ScannerBase::more()
{
    d_more = true;
}

inline std::string const &ScannerBase::match() const
{
    return d_match;
}
        
#endif






