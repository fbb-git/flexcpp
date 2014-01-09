#include "rules.ih"

void Rules::processCatchAllRule()
{
    d_startConditions.remove(d_rules.size() - 1);
    d_catchAll = d_rules.back();
    d_rules.pop_back();
}

