#include "patternval.ih"

void PatternVal::copyStates(States &states, 
                            unordered_map<size_t, size_t> const &old2new)
{
    for_each(old2new.begin(), old2new.end(),
        FnWrap::unary(copyState, old2new, states));
}
