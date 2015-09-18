#include "pattern.hh"

Pattern Pattern::plus(States &states, Pattern const &pattern)
{
    Pair pair = states.next2();      // create new Start/Final states

        // pattern's end connects to pattern begin and the new FINAL state.
    states[pattern.end()] = State(EMPTY, pattern.begin(), pair.second);

        // Start state connects to the pattern's begin
    states[pair.first] = State(EMPTY, pattern.begin(), 0);
    
    Pattern ret(pair);

    return ret;
}



