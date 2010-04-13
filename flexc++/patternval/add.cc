#include "patternval.ih"

void PatternVal::add(States &states, unordered_map<size_t, size_t> &old2new, 
                     size_t idx)
{
        // done if no link or if the idx is already in old2new
        //
    if (idx == 0 || old2new.find(idx) != old2new.end())
        return;

        // add a new state
        //
    old2new[idx] = states.next();

        // inspect the current state's transitions
        //
    add(states, old2new, states[idx].data().next1());
    add(states, old2new, states[idx].data().next2());
}
