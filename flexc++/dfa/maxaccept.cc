#include "dfa.ih"

int DFA::maxAccept(size_t rowIdx) const
{
    size_t maxState = *max_element(d_stateSet[rowIdx].begin(), 
                                   d_stateSet[rowIdx].end(),
                          FnWrap::binary(cmpAccept, *d_states));

//    cerr << "returning St " << maxState << " = " << 
//        (*d_states)[maxState].accept() << endl;

    return (*d_states)[maxState].accept();
}
