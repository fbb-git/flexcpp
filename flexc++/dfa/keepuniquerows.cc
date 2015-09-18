#include "dfa.hh"

void DFA::keepUniqueRows()
{
    std::vector<size_t> unique;

    inspectRows(unique);

    if (unique.back() == unique.size() - 1)
        return;

    s_verbose << "UNIQUE: ";
    if (s_verbose)
        copy(unique.begin(), unique.end(), 
                                    ostream_iterator<size_t>(s_verbose, ","));
    s_verbose << '\n';

    for (auto &row: d_row)
        row.uniqueMap(unique);

    shrinkDFA(unique);
}

