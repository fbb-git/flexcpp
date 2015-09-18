#include "state.hh"

State::State(size_t type, size_t next1, size_t next2)
:
    State(type, new StateData(next1, next2))
{}
