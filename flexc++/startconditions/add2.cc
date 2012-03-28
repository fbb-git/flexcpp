#include "startconditions.ih"

void StartConditions::add(size_t ruleIdx)
{
    // Add the rule to all active states
    for (auto &sc: d_active)
        sc->d_rules.push_back(ruleIdx);

    // If no (explicit) active states, add rule to INITIAL state and all inclusive states
    if (d_active.empty()) 
    {
bool printed = false;
    
    for (auto &element: d_hash) 
    {
cout << "MINI SCANNER " << element.first << '\n';

        if (element.second.d_type == INCLUSIVE)
{
    if (not printed)
    {
        cout << "add rule " << ruleIdx << " to: ";
        printed = true;
    }

    cout << element.first << ", ";
            if (
                element.second.d_rules.empty() ||
                element.second.d_rules.back() != ruleIdx
            )
                element.second.d_rules.push_back(ruleIdx);
}
cout << '\n';

    }

    }

}


