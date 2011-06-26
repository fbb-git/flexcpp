#include "dfas.ih"

void DFAs::build()
{
    for_each(
        d_rules.begin(), d_rules.end(), 
        [&](Rules::NameVector const &nameVector)
        {
            d_dfa.push_back( 
                {nameVector.name(), DFA(d_ranges, d_rules, d_states)} );
    
            // calls DFA::build
            d_dfa.back().second.build(nameVector.name(), nameVector.rules());
            
        }
    );
      //      FnWrap::unary(buildDFA, *this));
}
