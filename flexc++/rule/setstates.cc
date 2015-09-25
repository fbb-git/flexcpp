#include "rule.ih"

void Rule::setStates(vector<size_t> &prePostA, 
                     States const &states, size_t begin, size_t end)
{
    if 
    (
            begin == 0      // not a state (dead-end at state next fields)
        ||
            begin == end    // or all states processed
        ||                  // or already entered
            find(prePostA.begin(), prePostA.end(), begin) 
            !=
            prePostA.end()
    )
        return;             // then done here

    prePostA.push_back(begin);          // add this state to the destination

    setStates(prePostA, states, states[begin].next1(), end);    // follow the 
                                                                // 1st link

    setStates(prePostA, states, states[begin].next2(), end);    // follow the 
                                                                // 2nd link
}
