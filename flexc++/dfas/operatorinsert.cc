#include "dfas.ih"

ostream &operator<<(ostream &out, DFAs const &dfas)
{
    for_each(
        dfas.d_dfa.begin(), dfas.d_dfa.end(), 
        [&](DFAs::Pair const &dfaInfo)
        {
            out << "DFA for " << dfaInfo.first << '\n' << dfaInfo.second;
        }
    );

    return out;
}
