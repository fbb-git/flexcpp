#include "patternval.ih"

PatternVal PatternVal::plus(States &states, PatternVal const &pattern)
{
    States::Pair pair = states.next2();      // create new Start/Final states

        // pattern's end connects to pattern begin and the new FINAL state.
    states[pattern.end()] =                 
                State::factory(State::EMPTY, pattern.begin(), pair.second);

        // Start state connects to the pattern's begin
    states[pair.first] = State::factory(State::EMPTY, pattern.begin(), 0);
    
    PatternVal ret(pair);

    return ret;
}



