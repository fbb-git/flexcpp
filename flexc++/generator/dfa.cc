#include "generator.hh"

    // Generate a DFA in the lex.cc file.

void Generator::dfa(DFAs::Pair const &dfaPair, ostream &out, 
                    vector<string> &startStates,
                    vector<size_t> &dfaOffsets)
{
    out << "    // " << dfaPair.first << '\n';  // name of the DFA is shown
    startStates.push_back(dfaPair.first);
    dfaOffsets.push_back(*(dfaOffsets.rbegin()) + dfaPair.second->size());

    size_t index = 0;
    for (auto &row: *dfaPair.second)
        dfaRow(row, index, out);                // write the DFA's rows
}
