#include "dfa.ih"


void DFA::build(vector<size_t> const &active, Rules const &rules, 
                States &states)    
{
    d_ranges->clearUsed();

    vector<StateSet> stateSet(1);

    for_each(active.begin(), active.end(),          // compute the startSet  
        FnWrap::unary(fillStartSet, rules, stateSet[0]));

    stateSet[0] = states.eClosure(stateSet[0]);     // compute the e-closure
                                                    // of the start-set

    while (d_row.size() != stateSet.size())         // as long as we haven't
    {                                               // checked all state sets
            // add another row and determine transitions 
        d_row.push_back(DFARow(rules, states, stateSet, d_row.size(),
                              *d_ranges));
                                                    
        d_row.back().transitions();
    }

    d_row[0].setAcceptType();
}


