#include "dfa.ih"


void DFA::processRule(size_t rule, DFA &dfa,
                                  size_t rowIdx, bool parentFinal, 
                                  int acceptCount)
{
    DFARow &row = dfa.d_row[rowIdx];

    auto end = row.laRules().end();
    auto iter = find(row.laRules().begin(), end, rule);

    if (iter != end)
        processRow(*iter, rule, dfa, rowIdx, parentFinal, acceptCount);
}
