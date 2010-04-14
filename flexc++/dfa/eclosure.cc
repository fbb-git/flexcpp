#include "dfa.ih"

DFA::StateSet DFA::eClosure(StateSet &current)
{
    StateSet ret;
    ret.insert(0);      // initialize to state 0, which is never inspected

    while (not current.empty())
    {
        size_t next = *current.begin();     // pick a state number
        ret.insert(next);                   // add it to the `ret' set

        State const &nextState = d_states[next];

        if (nextState.type() == State::EMPTY)   // e-transition?
        {
            current.insert(nextState.data().next1());   // if so, add the 
            current.insert(nextState.data().next2());   //  next states
        }
                                            // remove states already in the 
                                            // `ret' set from current
        for (auto iter = ret.begin(), end = ret.end(); iter != end; ++iter)
            current.erase(*iter);
    }

    ret.erase(0);       // erase state 0 again
    return ret;
}
