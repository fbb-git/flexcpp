#include "state.hh"

State::State(unsigned char ch, size_t next1)
:
    State(ch, new StateData(next1, 0))
{}

