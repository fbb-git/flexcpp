#include "state.ih"

State State::factory(size_t type, string const &str, 
                                    size_t next1, size_t next2)
{
    State ret {type, new StateString(str, next1, next2)};

    return ret;
}
