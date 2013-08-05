#include "dfa.ih"

void DFA::shrinkDFA(vector<size_t> &unique)
{
    s_verbose << "DFA ROWS: " << d_row.size() << '\n';

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

        s_verbose << "Move row " << from << " to row " << to << '\n';

        d_row[to] = d_row[from];
        d_stateSet[to] = d_stateSet[from];

        ++to;
    }

    d_row.resize(to);

    if (not s_verbose.isActive())
        return;

    s_verbose << "NEW # OF ROWS: " << to << ", states per row:\n";

    for (size_t idx = 0; idx != to; ++idx)        
    {
        s_verbose << "Row " << idx << ": ";
        copy(
            d_stateSet[idx].begin(), d_stateSet[idx].end(),
            ostream_iterator<decltype(*d_stateSet[0].begin())>(s_verbose, ",")
        );
        s_verbose << '\n';
    }
    s_verbose << '\n';
}





