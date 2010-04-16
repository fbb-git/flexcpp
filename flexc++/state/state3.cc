#include "state.ih"

State::State(size_t type, StateData *data)
:
    d_data(data),
    d_type(type),
    d_accept(NONE)
{}
