#include "dfa.ih"

void DFA::propagateLAsteps(vector<size_t> const &postAstates,
                           size_t stateIdx, int steps)
{
    cerr << "PLA: " << stateIdx << endl;

    if (stateIdx == 0)
        return;

    State &thisState = (*d_states)[stateIdx];

    if (thisState.accept() < steps)
        thisState.setAccept(steps);

    auto thisIter = find(postAstates.begin(), postAstates.end(), stateIdx);
   
    
    if (thisState.type() != State::EMPTY)
        ++steps;

    size_t next = thisState.next1();

    if (find(postAstates.begin(), postAstates.end(), next) - thisIter > 0)    
        propagateLAsteps(postAstates, next, steps);    

    next = thisState.next2();

    if (find(postAstates.begin(), postAstates.end(), next) - thisIter > 0)    
        propagateLAsteps(postAstates, next, steps);    
}

