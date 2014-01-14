#include "pattern.ih"

void Pattern::jumpToEnd(States &states, PairVector &beginEnd, 
                                size_t lower, size_t upper, Map &eject)
{
    size_t exitState = beginEnd.back().second;      // target state 
                                                    //  for exit jumps

    for (size_t idx = lower; idx != upper; ++idx)   // add connections to the
    {                                               // exit-state
        states[eject[idx]] = State(EMPTY, beginEnd[idx].first, exitState);

        beginEnd[idx].first = eject[idx];    // new begin state
    }
}
