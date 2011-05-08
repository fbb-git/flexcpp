#include "state.ih"

State::State(size_t type)
:
    d_type(type),
    d_flag(NO_LOP),
    d_rule(-1)
{}
