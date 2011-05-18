#include "dfa.ih"

// See technical/dfa.yo

void DFA::build(std::string const &name, vector<size_t> const &active)    
{
    d_ranges->clearUsed();

        // start with the initial states of all rules that are active in this 
        // miniscanner (rule nrs provided by the active-vector) 
        // At this point: note which rules are LA rules and put these in the
        // rule-startset
    for_each(active.begin(), active.end(),              
        FnWrap::unary(fillStartSet, *d_rules, d_stateSet[0]));

        // compute the e-closure of the start-set
    d_stateSet[0] = d_states->eClosure(d_stateSet[0]);  

    if (d_verbose)
        cout << "States defining the initial rows of the `" << name << 
                                                                "' DFA:\n";

    while (d_row.size() != d_stateSet.size())       // as long as we haven't
    {                                               // checked all state sets
            // add another row and determine transitions 
        d_row.push_back(DFARow(*d_rules, *d_states, d_stateSet, d_row.size(),
                              *d_ranges));
        d_row.back().transitions();
        
        if (d_verbose)
        {
            cout << "Row " << d_row.size()-1 << ": ";
            copy (d_stateSet[d_row.size()-1].begin(), 
                  d_stateSet[d_row.size()-1].end(),
                  ostream_iterator<decltype(*d_stateSet[0].begin())>(
                                                                cout, ","));
            cout << '\n';
        }
    }

    if (d_verbose)
        cout << '\n';

    keepUniqueRows();

    keepViableTailCounts();
                            
    computeTailCounts();         // compute accept counts for LA rules

//    mergeFinalSet();        // calls DFARow::mergeFinalSet for each row.

}



