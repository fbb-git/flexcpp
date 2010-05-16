#include "dfa.ih"

// called from processLArule

void DFA::processRule(size_t ruleIdx, DFA &dfa, size_t rowIdx, 
                      int parentFinal, int tailSteps)
{
    DFARow &row = dfa.d_row[rowIdx];

    auto end = row.laRules().end();
    auto iter = find(row.laRules().begin(), end, ruleIdx);

    if (iter != end)
        processRow(*iter, ruleIdx, dfa, rowIdx, parentFinal, tailSteps);
}
