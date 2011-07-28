#include "patternval.ih"

#include <iostream>

size_t PatternVal::dupPattern(Map &map, States &states, size_t idx)
{
        // done if no link or if the idx is already in map
        //
    auto iter = map.find(idx);
    if (iter != map.end())
        return iter->second;

        // add a new state
        //
    size_t newIdx = states.next();
    states[newIdx] = states[idx];        // copy the existing state
    map[idx] = newIdx;                   // define the transition

        // inspect the current state's transitions
        //
    StateData const &link = states[newIdx].data();

    states[newIdx].setData(
        new StateData(
            dupPattern(map, states, link.next1()),
            dupPattern(map, states, link.next2())
        )
    );

    return newIdx;
}

