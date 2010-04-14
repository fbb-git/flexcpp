#include "states.ih"

size_t *States::next(size_t nStates)
{
    size_t *states = new size_t[nStates];

    for (size_t idx = 0; idx != nStates; ++idx)
        states[idx] = next();

    d_state[states[nStates - 1]] = State::factory(State::FINAL, 0, 0);

    return states;
}
