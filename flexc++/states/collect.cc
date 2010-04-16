#include "states.ih"

void States::collect(size_t idx)
{
    d_state[idx].setType(State::UNDETERMINED__);
    return d_free.push_back(idx);
}

