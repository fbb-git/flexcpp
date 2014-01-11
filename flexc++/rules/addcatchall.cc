#include "rules.ih"

void Rules::addCatchAll(size_t scIndex, size_t catchAllRuleIndex)
{
    d_startConditions.activate(scIndex);

    addIndex(catchAllRuleIndex);
}


