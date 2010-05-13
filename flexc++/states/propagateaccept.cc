//X#include "states.ih"
//X
//Xvoid States::propagateAccept(int state, int count)
//X{
//X    if (state == 0 || contains(state))
//X        return;
//X    
//X    d_ruleStates[state] = true;
//X
//X    State &curState = d_state[state];
//X
//X                                        // always store the max. accept 
//X                                        // count: received or current value
//X    curState.setAccept(count = max(curState.accept(), count));
//X
//X    count += curState.type() != State::EMPTY;
//X
//X    int next = curState.next1();
//X    if (!contains(next));
//X        propagateAccept(next, count);
//X
//X    next = curState.next2();
//X    if (!contains(next))
//X        propagateAccept(next, count);
//X
//X    d_ruleStates[state] = false;
//X}
