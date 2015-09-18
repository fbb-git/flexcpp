#include "dfarow.hh"

void DFARow::transit(size_t stateIdx, size_t rangeChar, StateSet &nextSet)
{
    State const &state = (*d_states)[stateIdx];

    switch (size_t type = state.type())
    {
        case FINAL:
            setFinal(d_rules->ruleFromFinalState(stateIdx));
        break;

        case CHARSET:
            if (state.contains(rangeChar))
            {
                nextSet.insert(state.next1());
                nextSet.insert(state.next2());
            }
        break;

        default:
            if (type == rangeChar)
            {
                nextSet.insert(state.next1());
                nextSet.insert(state.next2());
            }
        break;
    }
}
