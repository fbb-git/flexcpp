#include "patternval.ih"

spSemVal PatternVal::questionMark(States &states, SemVal &semVal)
{
    size_t idx = states.next();

    PatternVal &pattern = downCast<PatternVal>(semVal);

    states[idx] = State::factory(State::EMPTY, pattern.begin(), 
                                                pattern.end());

    spSemVal ret(new PatternVal( {idx, pattern.end()} ));

    return ret;
}
