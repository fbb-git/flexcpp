#include "dfas.ih"

void DFAs::buildDFA(Rules::NameVector const &nameVector, DFAs &dfas)
{
    dfas.d_dfa.push_back( {nameVector.first, DFA(dfas.d_ranges)} );

        // calls DFA::build
    dfas.d_dfa.back().second.build(nameVector.second, 
                                    dfas.d_rules, dfas.d_states);
}
