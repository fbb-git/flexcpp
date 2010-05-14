#include "dfarow.ih"

bool DFARow::hasPostAstates(size_t ruleIdx) const
{
    vector<size_t> const &postA = (*d_rules)[ruleIdx].postAstates();

    StateSet const &stateSet = (*d_stateSets)[ruleIdx];

    return find_if(stateSet.begin(), stateSet.end(), 
            FnWrap::unary(stateOfRule, postA)) != stateSet.end();
}

