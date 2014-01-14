#include "state.ih"

State::State(size_t type, size_t next1, size_t next2)
:
    State(d_type, new StateData(next1, next2))
{}
