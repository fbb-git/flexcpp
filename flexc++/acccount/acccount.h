#ifndef INCLUDED_ACCCOUNT_
#define INCLUDED_ACCCOUNT_

#include <iosfwd>
#include "../state/state.h"

class AccCount
{
    friend std::ostream &operator<<(std::ostream &out, AccCount const &la);

    public:
        enum Type       // the values are bit-flags
        {   
            DEFAULT,
    
            COUNT           = 1,        // d_accCount is used
            INCREMENTING    = 2,        // only POST states in the DFArow
    
            PRE             = 4,
            ACCEPT          = 8,
            POST            = 16,
    
            PROCESSED       = 32,       // processed by DFA::processAccCount
        };

    private:
            
        size_t d_rule;      // which LOP rule?
        size_t d_type;      // see above: d_type holds `Type' values
        size_t d_accCount;  // accept count

    public:
        AccCount(size_t ruleIdx, State::Flag flag);
        bool operator==(size_t rule) const;

        void addFlag(Type type);
        void addFlag(State::Flag flag);
        void setAccCount(int accCount);
        void setInc();

        bool inc() const;
        size_t accCount() const;
        size_t rule() const;

        Type type() const;        
};
        
inline AccCount::Type operator|(AccCount::Type lhs, AccCount::Type rhs)
{
    return static_cast<AccCount::Type>(static_cast<int>(lhs) | rhs);
}

inline AccCount::Type AccCount::type() const
{
    return static_cast<Type>(d_type);
}

inline bool AccCount::inc() const
{
    return d_type & INCREMENTING;
}

inline size_t AccCount::rule() const
{
    return d_rule;
}

//inline bool AccCount::final() const
//{
//    return d_type & FINAL_STATE;
//}

inline size_t AccCount::accCount() const
{
    return d_accCount;
}

//inline size_t AccCount::type() const
//{
//    return d_type;
//}

inline void AccCount::addFlag(Type type)
{
    d_type |= type;
}

inline void AccCount::addFlag(State::Flag flag)
{
    d_type |= 
        (
            flag == State::PRE  ? PRE :
            flag == State::POST ? POST :
                                  ACCEPT
        );
}

inline void AccCount::setAccCount(int accCount)
{
    d_accCount = accCount;
}

//inline void AccCount::setInc()
//{
//    d_type |= INCREMENTING;
//}
//
//inline void AccCount::setLOP()
//{
//    d_type |= USES_LOP;
//}
//
//inline void AccCount::setFinal()
//{
//    d_type |= FINAL_STATE;
//}

inline bool AccCount::operator==(size_t ruleIdx) const
{
    return d_rule == ruleIdx;
}

std::ostream &operator<<(std::ostream &out, AccCount const &la);

#endif
