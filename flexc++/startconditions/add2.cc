#include "startconditions.ih"

void StartConditions::add(size_t ruleIdx)
{
    for_each(
        d_active.begin(), d_active.end(),
        [=](StartCondition *sc)
        {
            sc->d_rules.push_back(ruleIdx);
        }
    );

    if (d_inclusive || d_active.empty())
        d_initialSC->d_rules.push_back(ruleIdx);
}
