#include "rules.ih"

void Rules::add(bool bol, Pattern const &pattern, Block const &block,
                RuleType type) 
{
    size_t ruleIdx = d_rules.size();        // the index of the rule to add

                                            // now add the rule
    d_rules.push_back( { d_states, bol, pattern, block, type } );

    Pair const &pair = d_rules.back().pair();   // the rule's begin/end states

    d_finalToRule[pair.second] = ruleIdx;   // associate end-state to rule

    setRule(pair.first, ruleIdx);

    d_startConditions.add(ruleIdx);
}    
