#include "startconditions.ih"

void StartConditions::add(size_t ruleIdx)
{
    for(auto sc: d_active)
        sc->d_rules.push_back(ruleIdx);

    if (d_inclusive || d_active.empty())
        d_initialSC->d_rules.push_back(ruleIdx);
}
