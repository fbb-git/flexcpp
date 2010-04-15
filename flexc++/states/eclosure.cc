#include "states.ih"

#include <iostream>

set<size_t> States::eClosure(set<size_t> &current) const
{
//cerr << "E-closure:\n";

    set<size_t> ret;
    ret.insert(0);      // initialize to state 0, which is never inspected

    while (not current.empty())
    {
        size_t next = *current.begin();     // pick a state number
        ret.insert(next);                   // add it to the `ret' set
//cerr << "   inspect " << next << '\n';

        State const &nextState = d_state[next];

        if (nextState.type() == State::EMPTY)   // e-transition?
        {
//cerr << "   empty transition, add: " << nextState.data().next1() << " and " <<
//                                        nextState.data().next2() << '\n';

            current.insert(nextState.data().next1());   // if so, add the 
            current.insert(nextState.data().next2());   //  next states
        }
                                            // remove states already in the 
                                            // `ret' set from current
        for (auto iter = ret.begin(), end = ret.end(); iter != end; ++iter)
{
//cerr << "erase: " << *iter << '\n';
            current.erase(*iter);
}
    }

    ret.erase(0);       // erase state 0 again

    return ret;
}
