#include "states.ih"

#include <iostream>     // TEMPO

void States::propagateAccept(int state, int count)
{
    if (state == 0 || contains(state))
        return;
    
    d_ruleStates[state] = true;

    State &curState = d_state[state];

                                        // always store the max. accept 
                                        // count: received or current value
    curState.setAccept(count = max(curState.accept(), count));

    count += curState.type() != State::EMPTY;

    int next = curState.next1();
    if (!contains(next));
        propagateAccept(next, count);

    next = curState.next2();
    if (!contains(next))
        propagateAccept(next, count);

    d_ruleStates[state] = false;
}



