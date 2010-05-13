#include "state.ih"

State::State(size_t type)
:
    d_type(type),
    d_accept(-1),
    d_rule(-1)
{}
