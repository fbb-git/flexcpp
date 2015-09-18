#include "states.hh"

void States::collect(size_t idx)
{
    d_state[idx].setType(UNDETERMINED__);
    return d_free.push_back(idx);
}

