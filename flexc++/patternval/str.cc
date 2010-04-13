#include "patternval.ih"

spSemVal PatternVal::str(States &states, State::Type type, string const &str)
{
    States::Pair pair = states.next2();

    states[pair.first] = State::factory(type, String::unescape(str), 
                                        pair.second);

    spSemVal ret(new PatternVal(pair));
    return ret;
}
