#include "dfarow.hh"

void DFARow::setFinal(size_t ruleIdx)
{
    size_t *target = 
            (*d_rules)[ruleIdx].bol() ? 
                &d_finalRule.second 
            : 
                &d_finalRule.first;

    if (ruleIdx < *target)
        *target = ruleIdx;
}
