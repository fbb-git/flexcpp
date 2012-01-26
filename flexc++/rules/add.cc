#include "rules.ih"

    // lineNr is always 1 too large as the parser detects the end of the rule
    // at the line following the rule's definition. Therefore lineNr is
    // here reduced by 1.
void Rules::add(bool bol, spSemUnion const &patternVal, Block const &block,
                string const &fileName, size_t lineNr)
{
    Pair const &pair = patternVal->value<PATTERN>().pair();

    d_rules.push_back( { d_states, bol, pair, block, fileName, lineNr - 1 } );

    size_t ruleIdx = d_rules.size() - 1;

    d_finalToRule[pair.second] = ruleIdx;

    setRule(pair.first, ruleIdx);

    d_startConditions.add(ruleIdx);
}    
