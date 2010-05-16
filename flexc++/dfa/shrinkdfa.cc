#include "dfa.ih"

void DFA::shrinkDFA(vector<size_t> &unique, vector<StateSet> &stateSet)
{
    cerr << "DFA ROWS: " << d_row.size() << endl;

    size_t to = 0;
    for (size_t from = 0, end = d_row.size(); from != end; ++from)
    {
        if (unique[from] == from)
        {
            ++to;
            continue;
        }
        if (unique[from] < to)
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
}
