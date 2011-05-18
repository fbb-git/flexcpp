#include "dfa.ih"

void DFA::transitTailCount(DFARow::MapValue const &rangeToRow, 
                          TailCount *fmTailCount, size_t fmRow, DFA &dfa)
{
    int toRow = rangeToRow.second;

    if (toRow == -1)        // no transition
        return;

//cout << " transiting from row " << fmRow << " to " << toRow << '\n';

    std::vector<TailCount> &tailCounts = dfa.d_row[toRow].tailCounts();
    auto endIter = tailCounts.end();
    auto iter = find(tailCounts.begin(), endIter, dfa.d_rule);

    if (iter == endIter)
        return;

//cout << "Next tailCount...\n";

    determineTailCount(*iter, toRow, fmTailCount, fmRow, dfa);
}
