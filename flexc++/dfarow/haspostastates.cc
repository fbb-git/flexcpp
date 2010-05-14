#include "dfarow.ih"

bool DFARow::hasPostAstates(size_t ruleIdx, size_t rowIdx) const
{
    vector<size_t> const &postA = (*d_rules)[ruleIdx].postAstates();

    StateSet const &stateSet = (*d_stateSets)[rowIdx];

    return find_if(stateSet.begin(), stateSet.end(), 
            FnWrap::unary(stateOfRule, postA)) != stateSet.end();
}

