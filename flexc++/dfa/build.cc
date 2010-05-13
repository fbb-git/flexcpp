#include "dfa.ih"

void DFA::build(vector<size_t> const &active, Rules const &rules, 
                States &states)    
{
    d_ranges->clearUsed();

    vector<StateSet> stateSet(1);

        // start with the initial states of all rules that are active in this 
        // miniscanner (rule nrs provided by the active-vector) compute
        // At this point: note which rules are LA rules and put these in the
        // rule-startset
    for_each(active.begin(), active.end(),              
        FnWrap::unary(fillStartSet, rules, stateSet[0]));

    stateSet[0] = states.eClosure(stateSet[0]);     // compute the e-closure
                                                    // of the start-set

    while (d_row.size() != stateSet.size())         // as long as we haven't
    {                                               // checked all state sets
            // add another row and determine transitions 
        d_row.push_back(DFARow(rules, states, stateSet, d_row.size(),
                              *d_ranges));
                                                    
        d_row.back().transitions();

// TEMPO: Display the states defining this row
    cout << "Row " << d_row.size()-1 << ": ";
    for (auto iter = stateSet[d_row.size()-1].begin(), end = 
    stateSet[d_row.size()-1].end(); iter != end; ++iter)
    cout << *iter << ',';
    cout << '\n';

    }

    processLArules();           // compute accept counts for LA rules

//X    d_row[0].setAcceptType();       // walk the DFA states and set
}                                   // the appropriate A-count



