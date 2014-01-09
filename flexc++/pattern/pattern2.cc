#include "pattern.ih"

Pattern::Pattern(States &states, Pattern const &lopLhs, Pattern const &lopRhs, 
                 size_t startCondition)
:
    d_lopData(new LopData {startCondition, lopLhs.pair().second,
                           lopLhs.duplicate(states) }),    
    d_pair(concatenate(states, lopLhs, lopRhs).pair())
{}
