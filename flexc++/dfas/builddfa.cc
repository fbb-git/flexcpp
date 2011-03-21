#include "dfas.ih"

void DFAs::buildDFA(Rules::NameVector const &nameVector, DFAs &dfas)
{
    dfas.d_dfa.push_back( {nameVector.name(), 
                           DFA(dfas.d_ranges, dfas.d_rules, dfas.d_states)} );


    
        // calls DFA::build
    dfas.d_dfa.back().second.build(nameVector.name(), nameVector.rules());
}
