#include "rules.ih"

void Rules::handleCatchAllRule()
{
    d_rules.back().setViable(true);
    d_startConditions.removeLastRule();
}
