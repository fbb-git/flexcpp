#include "startconditions.ih"

void StartConditions::add(size_t ruleIdx)
{
    for (auto &sc: d_active)    // add the rule to all active mini scanners
        sc->d_rules.push_back(ruleIdx);

    if (d_active.size())        // this rule is for specific mini scanners:
        return;                 // done

                                // no mini scanners were explicitly mentioned:
                                // add the rule to all inclusive mini scanners
    for (auto &element: d_scVector) 
    {
        if (element.second.d_type == INCLUSIVE)
            element.second.d_rules.push_back(ruleIdx);
    }
}


