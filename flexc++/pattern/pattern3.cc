#include "pattern.hh"

// This is a fixed-sized tail.

Pattern::Pattern(States &states, size_t tailLength,
                    Pattern const &lopLhs, Pattern const &lopRhs)
:
    d_lopData(new LopData {tailLength, 0} ),    
    d_pair(concatenate(states, lopLhs, lopRhs).pair())
{}
