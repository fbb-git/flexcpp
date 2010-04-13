#include "states.ih"

States::Pair States::next2()
{
    Pair ret {next(), next()};
    d_state[ret.second] = State::factory(State::FINAL);

    return ret;
}
