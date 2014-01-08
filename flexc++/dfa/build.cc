#include "dfa.ih"

// See technical/dfa.yo

void DFA::build(std::string const &name, vector<size_t> const &active)    
{
    d_ranges->clearUsedRanges();

        // start with the initial states of all rules that are active in this 
        // miniscanner (rule nrs provided by the active-vector) 
        // At this point: note which rules are LA rules and put these in the
        // rule-startset

    Size_tSet &start = d_stateSet[0];

    for (auto idx: active)
        start.insert((*d_rules)[idx].startState());

        // compute the e-closure of the start-set
    d_stateSet[0] = d_states->eClosure(d_stateSet[0]);  

    s_verbose << "States defining the initial rows of the `" << name << 
                                                                "' DFA:\n";

    while (d_row.size() != d_stateSet.size())       // as long as we haven't
    {                                               // checked all state sets
            // add another row and determine transitions 
        d_row.push_back(DFARow(*d_rules, *d_states, d_stateSet, d_row.size(),
                              *d_ranges));
        d_row.back().transitions();
        
        s_verbose << "Row " << d_row.size()-1 << ": ";
        if (s_verbose)
            copy (d_stateSet[d_row.size()-1].begin(), 
                  d_stateSet[d_row.size()-1].end(),
                  ostream_iterator<decltype(*d_stateSet[0].begin())>(
                                                            s_verbose, ","));
        s_verbose << '\n';
    }

    s_verbose << '\n';

    keepUniqueRows();

    d_nUsedRanges = d_ranges->nUsedRanges();
    d_ranges->copyUsedRanges(d_usedRanges);


cerr << "DFA " << name << " uses " << d_nUsedRanges << " ranges\n";
cerr << "nRanges: " << d_ranges->nRanges() << '\n';
    for (size_t idx = 0, end = d_ranges->nRanges(); idx++ != end; )
    {
        if (d_usedRanges.get()[idx - 1])
            cerr << setw(3) << idx;
    }
cerr << '\n';

    for (auto &row: d_row)
        row.setUsedRanges(d_usedRanges.get());
}






