#include "startconditions.ih"

void StartConditions::removeLastRule()
{
    for (auto &sc: d_active)    // remove the last (catch-all) rule from all
        sc->d_rules.pop_back(); // active mini scanners

    if (d_active.size())        // if a specific set of MSs was specified 
        return;                 // then we're now done

                                // no mini scanners were explicitly mentioned:
                                // so the rule was added to all inclusive mini
                                // scanners: remove it again
    for (auto &element: d_scVector) 
    {
        if (element.second.d_type == INCLUSIVE)
            element.second.d_rules.pop_back();
    }
}


