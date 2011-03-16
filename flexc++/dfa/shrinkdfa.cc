#include "dfa.ih"

void DFA::shrinkDFA(vector<size_t> &unique)
{
    if (d_verbose)
        cout << "DFA ROWS: " << d_row.size() << '\n';

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

        if (d_verbose)
            cout << "Move row " << from << " to row " << to << '\n';

        d_row[to] = d_row[from];
        d_stateSet[to] = d_stateSet[from];

        ++to;
    }

    d_row.resize(to);

    if (!d_verbose)
        return;

    cout << "NEW # OF ROWS: " << to << ", states per row:\n";

    for (size_t idx = 0; idx != to; ++idx)        
    {
        cout << "Row " << idx << ": ";
        copy(d_stateSet[idx].begin(), d_stateSet[idx].end(),
            ostream_iterator<decltype(*d_stateSet[0].begin())>(cout, ","));
        cout << '\n';
    }
    cout << '\n';
}





