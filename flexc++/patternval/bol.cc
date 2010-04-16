#include "patternval.ih"

spSemVal PatternVal::bol(States &states, SemVal &pattern)
{
    States::Pair pair = states.next2();

    states[pair.first] = State::factory(State::BOL, pair.second, 0);
    
    PatternVal bolPattern(pair);

    spSemVal ret = concatenate(states, bolPattern, pattern);
    return ret;
}



