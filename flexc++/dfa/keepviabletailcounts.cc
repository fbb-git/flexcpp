#include "dfa.ih"

void DFA::keepViableTailCounts()
{
    for_each(d_row.begin(), d_row.end(), DFARow::keepViableTailCounts);
}
