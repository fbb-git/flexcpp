#include "pattern.ih"

// This is a fixed-sized tail.

Pattern::Pattern(States &states, size_t startCondition,
                    Pattern const &lopLhs, Pattern const &lopRhs)
:
    d_lopData(new LopData {startCondition, lopLhs.pair().second,
                           lopLhs.duplicate(states) }),    
    d_pair(concatenate(states, lopLhs, lopRhs).pair())
{
    cerr << "Fixed sized tail rule\n";
}
