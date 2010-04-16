#include "startconditions.ih"

void StartConditions::add(size_t ruleIdx)
{
    for_each(d_active.begin(), d_active.end(),
        FnWrap::unary(addRule, ruleIdx));

    if (d_inclusive || d_active.empty())
        addRule(d_initialSC, ruleIdx);
}