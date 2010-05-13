#include "dfa.ih"


void DFA::processRule(size_t rule, std::vector<DFARow> &rows,
                                  size_t rowIdx, bool parentFinal, 
                                  int acceptCount)
{
    DFARow &row = rows[rowIdx];
    for_each(row.laRules().begin(), row.laRules().end(),
                FnWrap::unary(processRow, rule, rows, rowIdx, parentFinal,
                                acceptCount));
}
