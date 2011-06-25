#include "dfa.ih"

// This function computes the TailCounts of the TailCount elements in row 0 of
// the DFA. It calls computeTailCount to do the actual work.

void DFA::computeTailCounts()
{
    for_each(
        d_row[0].tailCounts().begin(), d_row[0].tailCounts().end(),
        [this](TailCount &tailCount)
        {
            this->visitTailCount(tailCount);
        }
    );
}
