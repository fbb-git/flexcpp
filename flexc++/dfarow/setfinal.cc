#include "dfarow.ih"

#include <iostream>

void DFARow::setFinal(size_t stateIdx)
{
    size_t rule = d_rules->hasFinalState(stateIdx);

    auto end = d_finalRule.end();
    if 
    (
        rule != UINT_MAX 
        && 
        find(d_finalRule.begin(), end, rule) == end
    )
        d_finalRule.push_back(rule);
}
