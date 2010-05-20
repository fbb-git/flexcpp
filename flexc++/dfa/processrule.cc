#include "dfa.ih"

// called from processFinAcInfo

void DFA::processRule(size_t ruleIdx, DFA &dfa, size_t rowIdx, 
                      int parentFinal, int tailSteps)
{
    DFARow &row = dfa.d_row[rowIdx];

    auto end = row.finAcInfos().end();
    auto iter = find(row.finAcInfos().begin(), end, ruleIdx);

    if (iter != end)
        processRow(*iter, ruleIdx, dfa, rowIdx, parentFinal, tailSteps);
}
