#include "pattern.ih"

Pattern Pattern::plus(States &states, Pattern const &pattern)
{
    States::Pair pair = states.next2();      // create new Start/Final states

        // pattern's end connects to pattern begin and the new FINAL state.
    states[pattern.end()] =                 
                State::factory(EMPTY, pattern.begin(), pair.second);

        // Start state connects to the pattern's begin
    states[pair.first] = State::factory(EMPTY, pattern.begin(), 0);
    
    Pattern ret(pair);

    return ret;
}



