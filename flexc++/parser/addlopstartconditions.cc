#include "parser.ih"

// this function is called after parse(), when all rules have been parsed. 
// if at least one LOP rule was found, the currently last rule in d_rules
// defines the catch-all rule used by the LOP rules.

// So at this time the catch all rule value can be set in the Rules object.

void Parser::addLopStartConditions()
{
    size_t nRules = d_rules.startConditions().size();

    if (nRules == d_lopStartCondition)      // no LOP rules encountered
        return;

    d_rules.processCatchAllRule();          // define the catch-all rule

                                            // define the LOP SCs
    for (; nRules != d_lopStartCondition; ++nRules)
        d_rules.addStartCondition("_" + to_string(nRules) + "__", true);
}
