#include "dfarow.ih"

void DFARow::setFinal(size_t stateIdx)
{
    size_t rule = d_rules->hasFinalState(stateIdx);
    if (rule < d_finalRule)
        d_finalRule = rule;
}
