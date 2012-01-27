#include "parser.ih"

void Parser::addBlockRule(spSemUnion const &rule, bool reset)
{
    d_rules.add(d_boln, rule->value<PATTERN>(), d_block,
                d_scanner.filename(), d_scanner.lineNr());
    if (reset)
        d_rules.resetStartConditions();
}

