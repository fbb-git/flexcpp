#include "dfas.ih"

void DFAs::removeRules(DFA const &dfa, set<size_t> &nonViable) const
{
    for (auto &row: dfa.rows())
    {
        auto &final = row.final();
        nonViable.erase(final.first);
        nonViable.erase(final.second);
    }
}
