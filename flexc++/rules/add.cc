#include "rules.ih"

void Rules::add(bool bol, spSemUnion const &patternVal, Block const &block)
{
    Pair const &pair = patternVal->value<PATTERN>().pair();

    d_rules.push_back( { d_states, bol, pair, block } );

    size_t ruleIdx = d_rules.size() - 1;

cout << "Defining rule index " << ruleIdx << '\n';

    d_finalToRule[pair.second] = ruleIdx;

    setRule(pair.first, ruleIdx);

    d_startConditions.add(ruleIdx);
}    
