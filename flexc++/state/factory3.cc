#include "state.ih"

State State::factory(unsigned char ch, size_t next1)
{
    State ret {ch, new StateData(next1, 0)};

    return ret;
}
