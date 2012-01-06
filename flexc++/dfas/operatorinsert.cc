#include "dfas.ih"

ostream &operator<<(ostream &out, DFAs const &dfas)
{
    for (auto &dfaInfo: dfas.d_dfa)
        out << "DFA for " << dfaInfo.first << '\n' << dfaInfo.second;

    return out;
}
