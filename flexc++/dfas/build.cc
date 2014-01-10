#include "dfas.ih"

void DFAs::build()
{
    for (auto &nameVector: d_rules)
    {
        d_dfa.push_back( 
            {nameVector.name(), new DFA(d_ranges, d_rules, d_states)} );

        // calls DFA::build
        d_dfa.back().second->build(nameVector.name(), nameVector.rules());
    }
}
