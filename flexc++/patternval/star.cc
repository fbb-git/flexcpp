#include "patternval.ih"

spSemVal PatternVal::star(States &states, SemVal &semVal)
{
    States::Pair pair = states.next2();     // create new Start/Final states

         // get the pattern to work with
    PatternVal &pattern = downCast<PatternVal>(semVal);

        // pattern's end connects to pattern begin and the new FINAL state.
    states[pattern.end()] =                 
                State::factory(State::EMPTY, pattern.begin(), pair.second);
    
        // new Start state connects to pattern begin + end
    states[pair.first] = State::factory(State::EMPTY, 
                                            pattern.begin(), pair.second);

    spSemVal ret(new PatternVal(pair));

    return ret;
}



