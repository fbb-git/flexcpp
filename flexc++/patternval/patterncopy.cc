#include "patternval.ih"

#include <iostream>

size_t PatternVal::patternCopy(States &states, size_t begin, size_t end)
{
    size_t nextFinal = states.next();

        // the unordered map starts out with the new final state
        // zero must be added since 0-transitions remain 0-transitions
    unordered_map<size_t, size_t> old2new =
    {
        {0, 0},
        {begin, end},
        {end, nextFinal}
    };

        // the `add' function adds new states for each of the states of the
        // current pattern to `states'. At the same time a unordered_map is
        // created relating the currrent state numbers to the new state
        // numbers.
        // Once this map is available, the actual state transition numbers
        // can be determined for the copied pattern.
        //
    add(states, old2new, states[begin].data().next1());
    add(states, old2new, states[begin].data().next2());

        // now that all states have been prepared, copy them
        // making sure that the proper transitions are set.

    cout << "OLD2NEW:\n";
    for_each(old2new.begin(), old2new.end(),
        [](unordered_map<size_t, size_t>::value_type const &vt)
        {
            cout << vt.first << " -> " << vt.second << '\n';
        }
    );

    copyStates(states, old2new);

    states[nextFinal] = State::factory(State::FINAL, 0, 0);

    return nextFinal;
}



