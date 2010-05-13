#include "dfa.ih"

void DFA::inspect(pair<size_t, size_t> const &transit, size_t oldRow, 
                    size_t rule, std::vector<DFARow> &rows,
                    bool parentFinal, int acceptCount)
{
    if (transit.second > oldRow)
        processRule(rule, rows, transit.second, parentFinal, acceptCount);
}
