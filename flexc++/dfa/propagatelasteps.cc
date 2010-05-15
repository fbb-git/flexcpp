#include "dfa.ih"

void DFA::propagateLAsteps(vector<bool> &visited, size_t stateIdx, int steps)
{
    if (stateIdx == 0 || visited[stateIdx])
        return;

    visited[stateIdx] = true;

    State &thisState = (*d_states)[stateIdx];

    if (thisState.accept() < steps)
        thisState.setAccept(steps);

    if (thisState.type() != State::EMPTY)
        ++steps;

    propagateLAsteps(visited, thisState.next1(), steps);    
    propagateLAsteps(visited, thisState.next2(), steps);    

    visited[stateIdx] = false;
}




