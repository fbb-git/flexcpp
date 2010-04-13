#include "state.ih"

State State::factory(size_t type, size_t next1, size_t next2)
{
    State ret {type, new StateData(next1, next2)};

    return ret;
}
