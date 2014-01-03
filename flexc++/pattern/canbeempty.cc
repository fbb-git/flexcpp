#include "pattern.ih"

bool Pattern::canBeEmpty(States const &states) const
{
    State const &state = states[d_pair.first];
    return 
        state.type() == EMPTY &&
        (
            state.next1() == d_pair.second 
            || 
            state.next2() == d_pair.second 
        );
}
