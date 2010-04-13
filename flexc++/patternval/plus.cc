#include "patternval.ih"

spSemVal PatternVal::plus(States &states, SemVal &semVal)
{
    size_t idx = states.next();
    states[idx] = State::factory(State::FINAL);

    PatternVal &pattern = downCast<PatternVal>(semVal);

    states[pattern.end()] = State::factory(State::EMPTY, pattern.begin(), 
                                                            idx);

    spSemVal ret(new PatternVal( {pattern.begin(), idx} ));

    return ret;
}



