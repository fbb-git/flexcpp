// #include "dfa.ih"
// 
// // called from processFinAc
// 
// void DFA::processRule(size_t ruleIdx, DFA &dfa, size_t rowIdx, 
//                       bool parentFinal, int tailSize)
// {
//     DFARow &row = dfa.d_row[rowIdx];
// 
//     auto end = row.finAcs().end();
//     auto iter = find(row.finAcs().begin(), end, ruleIdx);
// 
//     if (iter != end)
//         processRow(*iter, ruleIdx, dfa, rowIdx, parentFinal, tailSize);
// }
