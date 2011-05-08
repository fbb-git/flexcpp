#include "rules.ih"

void Rules::add(spSemVal const &logic, spSemVal const &patternVal, 
                Block const &block)

//void Rules::add(Pair const &pair, Block const &block)
{
    Pair const &pair = SemVal::downCast<PatternVal>(*patternVal).pair();

    d_rules.push_back( 
        {   d_states, SemVal::downCast<Logic>(*logic).value(),
            pair, block, d_source, d_lineNr
        } );

//    d_rules.push_back( {d_states, pair, block, d_source, d_lineNr} );

    size_t ruleIdx = d_rules.size() - 1;

    d_finalToRule[pair.second] = ruleIdx;

    setRule(pair.first, ruleIdx);

    d_startConditions.add(ruleIdx);
}    
