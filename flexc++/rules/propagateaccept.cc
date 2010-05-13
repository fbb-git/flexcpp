//X#include "rules.ih"
//X
//Xvoid Rules::propagateAccept()
//X{
//X    d_states.iniRuleStates();
//X    for_each(d_rules.begin(), d_rules.end(), 
//X        FnWrap::unary(propagate, d_states));
//X}
