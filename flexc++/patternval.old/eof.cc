#include "patternval.ih"

spSemVal PatternVal::eof(States &states)
{
    States::Pair pair = states.next2();

    states[pair.first] = State::factory(State::EOF__, pair.second, 0);

    spSemVal ret(new PatternVal(pair));
    return ret;
}
