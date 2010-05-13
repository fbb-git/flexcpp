#include "dfarow.ih"

void DFARow::setFinal(size_t ruleIdx)
{
    auto end = d_finalRule.end();
    if 
    (
        ruleIdx != UINT_MAX 
        && 
        find(d_finalRule.begin(), end, ruleIdx) == end
    )
        d_finalRule.push_back(ruleIdx);
}
