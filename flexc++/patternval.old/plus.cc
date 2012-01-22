#include "patternval.ih"

spSemVal PatternVal::plus(States &states, SemVal &semVal)
{
    States::Pair pair = states.next2();      // create new Start/Final states

         // get the pattern to work with
    PatternVal &pattern = downCast<PatternVal>(semVal);


        // pattern's end connects to pattern begin and the new FINAL state.
    states[pattern.end()] =                 
                State::factory(State::EMPTY, pattern.begin(), pair.second);

        // Start state connects to the pattern's begin
    states[pair.first] = State::factory(State::EMPTY, pattern.begin(), 0);
    
    spSemVal ret(new PatternVal(pair));

    return ret;
}



