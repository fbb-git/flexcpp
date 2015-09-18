#include "rules.hh"

void Rules::setRule(size_t stateIdx, size_t ruleIdx)
{
    if (stateIdx == 0)              // not a state
        return;

    State &state = d_states[stateIdx];

    if (state.rule() == ruleIdx)    // already set (next()s can jump back!)
        return;

    state.setRule(ruleIdx);

    setRule(state.next1(), ruleIdx);
    setRule(state.next2(), ruleIdx);
}
