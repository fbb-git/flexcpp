#include "dfa.ih"

// called from processRow

void DFA::inspect(pair<size_t, size_t> const &transit, size_t oldRow, 
                    size_t rule, DFA &dfa, int parentFinal, int tailSize)
{
    if (transit.second > oldRow)
        processRule(rule, dfa, transit.second, parentFinal, tailSize);
}
