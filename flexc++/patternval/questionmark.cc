#include "patternval.ih"

PatternVal PatternVal::questionMark(States &states, PatternVal const &pattern)
{
    size_t idx = states.next();     // new start state

        // connect the new Start state with the pattern and FINAL 
    states[idx] = State::factory(State::EMPTY, 
                                    pattern.begin(), pattern.end());

    PatternVal ret({idx, pattern.end()});

    return ret;
}
