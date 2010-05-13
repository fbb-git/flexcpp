#include "rules.ih"

void Rules::propagateAccept()
{
    d_states.iniRuleStates();
    for_each(d_rules.begin(), d_rules.end(), 
        FnWrap::unary(propagate, d_states));
}
