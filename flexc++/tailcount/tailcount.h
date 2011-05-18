#ifndef INCLUDED_TAILCOUNT_
#define INCLUDED_TAILCOUNT_

#include <iosfwd>
#include "../state/state.h"

class TailCount
{
    friend std::ostream &operator<<(std::ostream &out, TailCount const &la);

    public:
        enum Type       // the values are bit-flags
        {   
            DEFAULT,
    
            COUNT           = 1,        // d_tailCount is used
            INCREMENTING    = 2,        // only POST states in the DFArow
    
            PRE             = 4,
            ACCEPT          = 8,
            POST            = 16,
    
            PROCESSED       = 32,       // processed by DFA::processTailCount
        };

    private:
            
        size_t d_rule;      // which LOP rule?
        size_t d_type;      // see above: d_type holds `Type' values
        size_t d_tailCount;  // accept count

    public:
        TailCount(size_t ruleIdx, State::Flag flag);
        bool operator==(size_t rule) const;

        void addFlag(Type type);
        void addFlag(State::Flag flag);
        void setTailCount(int tailCount);
        void setInc();

        bool inc() const;
        size_t tailCount() const;
        size_t rule() const;

        Type type() const;
};
        
inline TailCount::Type operator|(TailCount::Type lhs, TailCount::Type rhs)
{
    return static_cast<TailCount::Type>(static_cast<int>(lhs) | rhs);
}

inline TailCount::Type TailCount::type() const
{
    return static_cast<Type>(d_type);
}

inline bool TailCount::inc() const
{
    return d_type & INCREMENTING;
}

inline size_t TailCount::rule() const
{
    return d_rule;
}

//inline bool TailCount::final() const
//{
//    return d_type & FINAL_STATE;
//}

inline size_t TailCount::tailCount() const
{
    return d_tailCount;
}

//inline size_t TailCount::type() const
//{
//    return d_type;
//}

inline void TailCount::addFlag(Type type)
{
    d_type |= type;
}

inline void TailCount::addFlag(State::Flag flag)
{
    d_type |= 
        (
            flag == State::PRE  ? PRE :
            flag == State::POST ? POST :
                                  ACCEPT
        );
}

inline void TailCount::setTailCount(int tailCount)
{
    d_tailCount = tailCount;
}

//inline void TailCount::setInc()
//{
//    d_type |= INCREMENTING;
//}
//
//inline void TailCount::setLOP()
//{
//    d_type |= USES_LOP;
//}
//
//inline void TailCount::setFinal()
//{
//    d_type |= FINAL_STATE;
//}

inline bool TailCount::operator==(size_t ruleIdx) const
{
    return d_rule == ruleIdx;
}

std::ostream &operator<<(std::ostream &out, TailCount const &la);

#endif
