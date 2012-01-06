#include "dfa.ih"

void DFA::keepUniqueRows()
{
    std::vector<size_t> unique;

    inspectRows(unique);

    if (unique.back() == unique.size() - 1)
        return;

    if (d_verbose)
    {
        cout << "UNIQUE: ";
        copy(unique.begin(), unique.end(), 
                                    ostream_iterator<size_t>(cout, ","));
        cout << '\n';
    }

    for (auto &row: d_row)
        row.uniqueMap(unique);

    shrinkDFA(unique);
}

