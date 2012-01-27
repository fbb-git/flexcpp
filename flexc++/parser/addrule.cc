#include "parser.ih"

void Parser::addRule(spSemUnion const &rule, bool reset)
{
    d_rules.add(d_boln, rule->value<PATTERN>(), Block(), 
                d_scanner.filename(), d_scanner.lineNr());
    if (reset)
        d_rules.resetStartConditions();
}

