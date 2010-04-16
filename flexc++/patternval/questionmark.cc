#include "patternval.ih"

spSemVal PatternVal::questionMark(States &states, SemVal &semVal)
{
    size_t idx = states.next();     // new start state

        // get the pattern to work with
    PatternVal &pattern = downCast<PatternVal>(semVal);

        // connect the new Start state with the pattern and FINAL 
    states[idx] = State::factory(State::EMPTY, 
                                    pattern.begin(), pattern.end());

    spSemVal ret(new PatternVal( {idx, pattern.end()} ));

    return ret;
}
