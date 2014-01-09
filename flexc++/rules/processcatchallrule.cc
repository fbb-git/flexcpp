#include "rules.ih"

void Rules::processCatchAllRule()
{
    d_catchAllIndex = d_rules.size() - 1;

    d_startConditions.remove(d_catchAllIndex);
}

