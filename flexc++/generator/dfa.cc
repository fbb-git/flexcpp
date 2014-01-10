#include "generator.ih"

    // Generate a DFA in the lex.cc file.

void Generator::dfa(DFAs::Pair const &dfaPair, ostream &out, 
                    vector<RuleFlag> &rf, 
                    vector<string> &startStates,
                    vector<size_t> &dfaOffsets)
{
    if 
    (
        find(startStates.begin(), startStates.end(), dfaPair.first) !=
        startStates.end()
    )
        return;

    out << "    // " << dfaPair.first << '\n';  // name of the DFA is shown
    startStates.push_back(dfaPair.first);
    dfaOffsets.push_back(*(dfaOffsets.rbegin()) + dfaPair.second->size());

    size_t index = 0;
    for (auto &row: *dfaPair.second)
        dfaRow(row, index, out, rf);            // write the DFA's rows
}
