#include "dfas.ih"

void DFAs::build()
{
    size_t scIndex = 0;
    for (auto &sc: d_rules)
    {
        d_rules.checkUserSC(scIndex++);

        d_dfa.push_back( 
            {sc.first, new DFA(d_ranges, d_rules, d_states)} );

        // calls DFA::build
        d_dfa.back().second->build(sc.first, sc.second.rules());
    }
}
