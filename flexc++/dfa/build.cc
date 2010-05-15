#include "dfa.ih"

void DFA::build(vector<size_t> const &active)    
{
    d_ranges->clearUsed();

    vector<StateSet> stateSet(1);

        // start with the initial states of all rules that are active in this 
        // miniscanner (rule nrs provided by the active-vector) compute
        // At this point: note which rules are LA rules and put these in the
        // rule-startset
    for_each(active.begin(), active.end(),              
        FnWrap::unary(fillStartSet, *d_rules, stateSet[0]));

    stateSet[0] = d_states->eClosure(stateSet[0]);  // compute the e-closure
                                                    // of the start-set

    size_t nextRow = 0;
    while (d_row.size() != stateSet.size())         // as long as we haven't
    {                                               // checked all state sets
            // add another row and determine transitions 
        d_row.push_back(DFARow(*d_rules, *d_states, stateSet, d_row.size(),
                              *d_ranges));
        DFARow &last = d_row.back();
        last.transitions();

        size_t useRow = available(last);
        if (useRow == d_unique.size())         // unique row
            d_unique.push_back(nextRow++);
        else 
            d_unique.push_back(d_unique[useRow]);
        
// TEMPO: Display the states defining this row
    cout << "Row " << d_row.size()-1 << ": ";
    for (auto iter = stateSet[d_row.size()-1].begin(), end = 
    stateSet[d_row.size()-1].end(); iter != end; ++iter)
    cout << *iter << ',';
    cout << '\n';

    }

//    cerr << "UNIQUE: ";
//    copy(d_unique.begin(), d_unique.end(), 
//            ostream_iterator<size_t>(cerr, ","));
//    cerr << endl;

    keepUniqueRows();

    cerr << "DFA ROWS: " << d_row.size() << endl;

    size_t to = 0;
    for (size_t from = 0, end = d_row.size(); from != end; ++from)
    {
        if (d_unique[from] == from)
        {
            ++to;
            continue;
        }
        if (d_unique[from] < to)
            continue;
        cerr << "Move row " << from << " to row " << to << endl;

        d_row[to] = d_row[from];
        stateSet[to] = stateSet[from];

        ++to;
    }

    d_row.resize(to);

    cerr << "NEW # OF ROWS: " << to << ", states per row:\n";
    for (size_t idx = 0; idx != to; ++idx)        
    {
        cout << "Row " << idx << ": ";
        for (auto iter = stateSet[idx].begin(), end = 
        stateSet[idx].end(); iter != end; ++iter)
        cout << *iter << ',';
        cout << '\n';
    }

    processLArules();           // compute accept counts for LA rules
}



