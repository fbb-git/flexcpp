#include "dfarow.ih"

void DFARow::setAcceptRule(size_t stateIdx)
{
    int rule = d_rules->hasAcceptState(stateIdx);
    if (rule != -1)
        d_acceptRule.insert(rule);
}
