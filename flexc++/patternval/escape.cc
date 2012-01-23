#include "patternval.ih"

PatternVal PatternVal::escape(States &states, std::string const &ch)
{
    States::Pair pair = states.next2();

    states[pair.first] = 
        State::factory(
            static_cast<unsigned char>(String::unescape(ch)[0]), 
            pair.second
        );

    PatternVal ret(pair);
    return ret;
}
