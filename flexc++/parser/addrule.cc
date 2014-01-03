#include "parser.ih"

    // lineNr is always 1 too large as the parser detects the end of the rule
    // at the line following the rule's definition. Therefore lineNr is
    // here reduced by 1.
void Parser::addRule(Pattern const &rule, bool reset)
{
    d_rules.add(
        d_boln, rule, 
        d_useLOP, d_lhs, d_rhs,     // allow the rule to store the lhs/rhs
                                    // patterns in case / was used.
        Block(d_scanner.lineNr(), d_scanner.filename())
    );

    if (reset)
        d_rules.resetStartConditions();
}


