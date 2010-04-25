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
//    int d_LAsize;
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
        bool callExecute();
        void charToMatchBuffer();
        bool interactiveRuleMatched();
        bool atBOL() const;
        bool atEOF() const;
        bool streamPopped();
        void reRead();
        bool ruleMatched();
        void notHandledChar() const;

        void handleAcceptState();       // on values 2 and 3, change to enum!

    private:
        bool interactiveAndEOLN() const;
        int selectRule() const;
        bool plainChar() const;
        void saveLookahead();

        void updateHeadSize();
        void setHeadSizeOnce();
        Accept &acceptRecord();         // for the current state
        int acceptStateType() const;
        int acceptRule() const;         // rule # at current state
};

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

inline bool ScannerBase::interactiveAndEOLN() const
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

inline bool ScannerBase::interactiveRuleMatched()
{
    return interactiveAndEOLN() ?
                ruleMatched()
            :
                false;
}

        
#endif






