#include "pattern.ih"

Pattern Pattern::escape(States &states, std::string const &ch)
{
    Pair pair = states.next2();

    states[pair.first] = 
        State::factory(
            static_cast<unsigned char>(String::unescape(ch)[0]), 
            pair.second
        );

    Pattern ret(pair);
    return ret;
}
