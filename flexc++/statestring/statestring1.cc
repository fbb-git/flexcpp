#include "statestring.hh"

StateString::StateString(std::string const &str, size_t next1, size_t next2)
:
    StateData(next1, next2),
    d_str(str)
{}
