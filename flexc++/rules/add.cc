#include "rules.ih"

void Rules::add(Pair const &pair, size_t accept, Block const &block)
{
    d_rules.push_back( {d_states, pair, accept, block, d_source, d_lineNr} );
    size_t ruleIdx = d_rules.size() - 1;

    d_finalToRule[pair.second] = ruleIdx;

    if (accept)
        setRuleIndices(pair.first, ruleIdx);

    d_startConditions.add(ruleIdx);
}    
