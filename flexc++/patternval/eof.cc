#include "patternval.ih"

PatternVal PatternVal::eof(States &states)
{
    States::Pair pair = states.next2();

    states[pair.first] = State::factory(State::EOF__, pair.second, 0);

    PatternVal ret(pair);
    return ret;
}
