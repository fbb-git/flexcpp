#include "patternval.ih"

spSemVal PatternVal::plain(States &states, std::string const &ch)
{
    States::Pair pair = states.next2();

    states[pair.first] = 
        State::factory(
            static_cast<unsigned char>(String::unescape(ch)[0]), 
            pair.second
        );

    spSemVal ret(new PatternVal(pair));
    return ret;
}
