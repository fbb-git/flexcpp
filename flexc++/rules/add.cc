#include "rules.ih"

void Rules::add(Pair const &pair, size_t accept, string const &action)
{
    d_rules.push_back( {d_states, pair, accept, action} );
    size_t ruleIdx = d_rules.size() - 1;

    d_finalToRule[pair.second] = ruleIdx;

    if (accept)
    {
        setRuleIndices(pair.first, ruleIdx);
        d_LArules.push_back(ruleIdx);   // Rule ruleIdx uses the LA operator
    }
    d_startConditions.add(ruleIdx);
}    
