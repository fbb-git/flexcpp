//#include "generator.ih"
//
//void Generator::dfa(DFAs::Pair const &dfaPair, ostream &out, 
//                    vector<FinAc> &finAcs, 
//                    vector<string> &startStates,
//                    vector<size_t> &dfaOffsets)
//{
//    if 
//    (
//        find(startStates.begin(), startStates.end(), dfaPair.first) !=
//        startStates.end()
//    )
//        return;
//
//    out << "    // " << dfaPair.first << '\n';
//    startStates.push_back(dfaPair.first);
//    dfaOffsets.push_back(*(dfaOffsets.rbegin()) + dfaPair.second.size());
//
//    size_t index = 0;
//    for_each(dfaPair.second.begin(), dfaPair.second.end(), 
//                FnWrap::unary(dfaRow, index, out, finAcs));
//}
//
//
//
//
//
//
//


