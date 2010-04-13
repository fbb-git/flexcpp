#include "patternval.ih"

spSemVal PatternVal::star(States &states, SemVal &semVal)
{
    PatternVal &pattern = downCast<PatternVal>(semVal);

    States::Pair pair = states.next2();

    states[pair.first] = State::factory(State::EMPTY, pattern.begin(), 
                                                      pair.second);
    states[pattern.end()] = states[pair.first];
    
    spSemVal ret(new PatternVal(pair));

    return ret;
}



