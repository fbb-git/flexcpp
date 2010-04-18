#include "dfas.ih"

void DFAs::showDFA(Pair const &dfaInfo, ostream &out)
{
    out << "DFA for " << dfaInfo.first << '\n' <<
            dfaInfo.second;
            
}
