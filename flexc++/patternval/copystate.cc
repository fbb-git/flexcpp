#include "patternval.ih"

void PatternVal::copyState(pair<size_t, size_t> const &fromTo, 
                            unordered_map<size_t, size_t> const &old2new,
                            States &states)
{
    if (fromTo.first == 0)
        return;

    states[fromTo.second] = states[fromTo.first];

    auto iter = old2new.find( states[fromTo.first].data().next1() );
    if (iter == old2new.end())      // next state is the final state,
        return;                     // which isn't in old2new

    states[fromTo.second].data().set(
        iter->second,
        old2new.find( states[fromTo.first].data().next2() )->second
    );
}
