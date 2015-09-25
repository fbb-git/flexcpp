#include "pattern.ih"

bool Pattern::empty(States const &states, size_t idx)
{
    State const &state = states[idx];

    switch (state.type())
    {
        case EMPTY:
        return empty(states, state.next1()) || empty(states, state.next2());

        case FINAL:
        return true;

        default:
        return false;
    }
}
