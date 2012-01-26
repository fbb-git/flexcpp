#include "pattern.ih"

Pattern Pattern::questionMark(States &states, Pattern const &pattern)
{
    size_t idx = states.next();     // new start state

        // connect the new Start state with the pattern and FINAL 
    states[idx] = State::factory(State::EMPTY, 
                                    pattern.begin(), pattern.end());

    Pattern ret({idx, pattern.end()});

    return ret;
}
