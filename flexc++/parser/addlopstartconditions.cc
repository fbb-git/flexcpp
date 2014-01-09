#include "parser.ih"

void Parser::addLopStartConditions()
{
    size_t nRules = d_rules.startConditions().size();

    if (nRules == d_lopStartCondition)      // no LOP rules encountered
        return;

    d_rules.handleCatchAllRule();

    for (; nRules != d_lopStartCondition; ++nRules)
        d_rules.addStartCondition("_" + to_string(nRules) + "__", true);
}
