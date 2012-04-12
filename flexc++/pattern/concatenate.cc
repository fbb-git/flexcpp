#include "pattern.ih"

// States:
//          B1 -> E1  and B2 -> E2
// becomes:
//          B1 -> E1 -> E2, where B2 is assigned to E1
// B2 is returned to the State's free store.

Pattern Pattern::concatenate(States &states, Pattern const &lhs,
                                                   Pattern const &rhs)
{
    Options::regexCall("concatenate");

    states[lhs.end()] = states[rhs.begin()];
    states.collect(rhs.begin());

    Pattern ret({lhs.begin(), rhs.end()} );

    return ret;
}



