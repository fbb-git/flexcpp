#include "rules.hh"

void Rules::processCatchAllRule()
{
    d_startConditions.remove(--d_nUserRules);
    d_catchAll = d_rules.back();
    d_rules.pop_back();
}

