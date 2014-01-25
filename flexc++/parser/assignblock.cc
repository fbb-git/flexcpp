#include "parser.ih"

void Parser::assignBlock()
{
    if (d_nullMatchingRules)
        return;

    d_rules.assignBlock(d_block);   // assign the action block to all
}
