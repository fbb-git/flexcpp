#include "dfas.ih"

void DFAs::build()
{
    size_t scIndex = 0;
    for (auto &nameVector: d_rules)
    {
        d_rules.checkUserSC(scIndex++);

        d_dfa.push_back( 
            {nameVector.name(), new DFA(d_ranges, d_rules, d_states)} );

        // calls DFA::build
        d_dfa.back().second->build(nameVector.name(), nameVector.rules());
    }
}
