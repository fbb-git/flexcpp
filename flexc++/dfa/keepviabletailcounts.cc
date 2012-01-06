#include "dfa.ih"

void DFA::keepViableTailCounts()
{
    for (auto &row: d_row)
        DFARow::keepViableTailCounts(row);
}
