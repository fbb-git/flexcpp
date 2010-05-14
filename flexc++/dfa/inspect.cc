#include "dfa.ih"

void DFA::inspect(pair<size_t, size_t> const &transit, size_t oldRow, 
                    size_t rule, DFA &dfa, bool parentFinal, int acceptCount)
{
    if (transit.second > oldRow)
        processRule(rule, dfa, transit.second, parentFinal, acceptCount);
}
