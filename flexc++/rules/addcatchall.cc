#include "rules.ih"

void Rules::addCatchAll(Rule const &rule, size_t catchAllIndex)
{
    Pattern const &pattern = rule.pattern();

    size_t scIndex = pattern.scIndex();

    d_startConditions.activate(scIndex);

    addIndex(catchAllIndex);
}


