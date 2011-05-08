#ifndef INCLUDED_STATEDATA_
#define INCLUDED_STATEDATA_

#include <cstddef>

#include "../semval/semval.h"

class StateData: public SemVal
{
    size_t d_next1;         // 0: no next state(s)
    size_t d_next2;

    public:
        StateData(size_t next1, size_t next2);

        size_t next1() const;
        size_t next2() const;
        void set(size_t next1, size_t next2 = 0);
        void set2nd(size_t next2);
};

inline size_t StateData::next1() const
{
    return d_next1;
}
        
inline size_t StateData::next2() const
{
    return d_next2;
}
        
inline void StateData::set(size_t next1, size_t next2)
{
    d_next1 = next1;
    d_next2 = next2;
}
        
inline void StateData::set2nd(size_t next2)
{
    d_next2 = next2;
}
        
#endif

