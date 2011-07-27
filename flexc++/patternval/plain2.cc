#include "patternval.ih"

#include <iostream>

spSemVal PatternVal::plain(States &states, std::string const &ch)
{
    States::Pair pair = states.next2();

cout << "Received: " << ch << '\n';

int int_ch;

    states[pair.first] = 
        State::factory(
int_ch =             static_cast<unsigned char>(String::unescape(ch)[0]), 
            pair.second
        );

cout << "Converted to: " << int_ch << '\n';

    spSemVal ret(new PatternVal(pair));
    return ret;
}
