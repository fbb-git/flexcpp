#include "rules.ih"

void Rules::setRuleIndices(size_t state, size_t ruleIndex)
{
    if 
    (
        state == 0              // not a state
        ||
        d_states[state].rule() != -1    // or already set, then
    )
        return;                 // done

    State &thisState = d_states[state];

    thisState.setRule(ruleIndex);

    setRuleIndices(thisState.next1(), ruleIndex);
    setRuleIndices(thisState.next2(), ruleIndex);
}
