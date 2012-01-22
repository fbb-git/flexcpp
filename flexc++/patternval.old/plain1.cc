#include "patternval.ih"

spSemVal PatternVal::plain(States &states, size_t ch)
{
    States::Pair pair = states.next2();

    states[pair.first] = State::factory(ch, pair.second);

    spSemVal ret(new PatternVal(pair));
    return ret;
}
