#include "state.hh"

State::State(size_t type, string const &str, size_t next1, size_t next2)
:
    State(type, new StateString(str, next1, next2))
{}
