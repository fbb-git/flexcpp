#include "dfa.ih"

void DFA::build(vector<size_t> const &active)    
{
    d_ranges->clearUsed();

        // start with the initial states of all rules that are active in this 
        // miniscanner (rule nrs provided by the active-vector) compute
        // At this point: note which rules are LA rules and put these in the
        // rule-startset
    for_each(active.begin(), active.end(),              
        FnWrap::unary(fillStartSet, *d_rules, d_stateSet[0]));

        // compute the e-closure of the start-set
    d_stateSet[0] = d_states->eClosure(d_stateSet[0]);  

    while (d_row.size() != d_stateSet.size())       // as long as we haven't
    {                                               // checked all state sets
            // add another row and determine transitions 
        d_row.push_back(DFARow(*d_rules, *d_states, d_stateSet, d_row.size(),
                              *d_ranges));
        d_row.back().transitions();
        
// TEMPO: Display the states defining this row
    cout << "Row " << d_row.size()-1 << ": ";
    for (auto iter = d_stateSet[d_row.size()-1].begin(), end = 
    d_stateSet[d_row.size()-1].end(); iter != end; ++iter)
    cout << *iter << ',';
    cout << '\n';

    }

    keepUniqueRows();
    processFinAc();           // compute accept counts for LA rules
    mergeFinalSet();
}



