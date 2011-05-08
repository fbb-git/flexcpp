#include "dfa.ih"

// This function computes the AccCounts of the AccCount elements in row 0 of
// the DFA. It calls computeAccCount to do the actual work.

void DFA::computeAccCounts()
{
    for_each(d_row[0].accCounts().begin(), d_row[0].accCounts().end(),
             FnWrap::unary(computeAccCount, *this));
}
