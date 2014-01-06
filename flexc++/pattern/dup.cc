#include "pattern.ih"

size_t Pattern::dup(Map &indexMap, States &states, size_t index)
{
    if (index == 0)                     // index 0: end of state chain.
        return 0;

    auto iter = indexMap.find(index);
    if (iter != indexMap.end())              // index already known
        return iter->second;


    size_t next = states.next();        // next state
    indexMap[index] = next;

    states[next] = states[index];       // copy the source state

    states[next].setData(
        new StateData(
            dup(indexMap, states, states[index].next1()),
            dup(indexMap, states, states[index].next2())
        )
    );

    return next;    
}
