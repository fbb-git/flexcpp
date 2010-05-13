//X#include "dfarow.ih"
//X
//Xvoid DFARow::setAcceptRule(size_t stateIdx)
//X{
//X    int rule = d_rules->hasAcceptState(stateIdx);
//X    if (rule != -1)
//X        d_acceptRule.insert(rule);
//X}
