#include "generator.ih"

void Generator::dfa(DFA::Pair const &dfaPair, ostream &out, 
                    vector<pair<char, size_t>> &accept,
                    vector<string> &startStates,
                    vector<size_t> &dfaOffsets)
{
    if 
    (
        find(startStates.begin(), startStates.end(), dfaPair.first) !=
        startStates.end()
    )
        return;

    startStates.push_back(dfaPair.first);
    dfaOffsets.push_back(*(dfaOffsets.rbegin()));

    out << "    {";

    for_each(dfaPair.second.begin(), dfaPair.second.end(), 
                FnWrap::unary(transitions, out, accept));

    out << ',' << static_cast<int>(dfaPair.second.final()) << " }\n";
}
