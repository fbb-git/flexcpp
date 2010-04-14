#include "dfa.ih"

void DFA::build(vector<size_t> const &active, Rules const &rules, 
                size_t size)    // number of character ranges
{
    vector<StateSet> stateSet(1);

    for_each(active.begin(), active.end(),          // compute the startSet  
        FnWrap::unary(fillStartSet, rules, stateSet[0]));

    stateSet[0] = eClosure(stateSet[0]);            // compute the e-closure
                                                    // of the start-set

    while (d_row.size() != stateSet.size())         // as long as we haven't
    {                                               // checked all state sets
        d_row.pushback(DFARow());                   // add another row
                                                    // and determine
                                                    // transitions 
        d_row.back().transitions(stateSet[d_row.size() - 1], stateSet, 
                                 d_states, size);
    }
}
