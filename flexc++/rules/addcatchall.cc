#include "rules.ih"

void Rules::addCatchAll()
{
    Pair const &pair = d_rules[d_catchAllIndex].pair();

    d_finalToRule[pair.second] = d_catchAllIndex;

    setRule(pair.first, d_catchAllIndex);

    d_startConditions.add(d_catchAllIndex);
}    
