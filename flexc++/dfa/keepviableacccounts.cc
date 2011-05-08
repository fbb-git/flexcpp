#include "dfa.ih"

void DFA::keepViableAccCounts()
{
    for_each(d_row.begin(), d_row.end(), DFARow::keepViableAccCounts);
}
