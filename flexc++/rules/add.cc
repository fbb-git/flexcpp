#include "rules.ih"

void Rules::add(bool bol, Pattern const &pattern, Block const &block,
                RuleType type) 
{
    d_rules.push_back( { d_states, bol, pattern, block, type } );

    Pair const &pair = d_rules.back().pair();

    size_t ruleIdx = d_rules.size() - 1;

    d_finalToRule[pair.second] = ruleIdx;

    setRule(pair.first, ruleIdx);

    d_startConditions.add(ruleIdx);
}    
