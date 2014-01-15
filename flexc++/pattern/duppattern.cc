#include "pattern.ih"

size_t Pattern::dupPattern(Map &map, States &states, size_t idx)
{
            // done if the idx is already in `map'
    auto iter = map.find(idx);
    if (iter != map.end())
        return iter->second;

        // add a new state
    size_t newIdx = states.next();

    map[idx] = newIdx;                   // define the transition

        // inspect the current state's transitions
    StateData const &link = states[idx].data();

    states[newIdx].dup(
                        states[idx], 
                        dupPattern(map, states, link.next1()),
                        dupPattern(map, states, link.next2())
                    );

    return newIdx;
}



