#include "dfarow.ih"

void DFARow::setFinal(size_t ruleIdx)
{
    if (ruleIdx != UINT_MAX)
        d_finalRule.insert(ruleIdx);
}
