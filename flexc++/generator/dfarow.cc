#include "generator.ih"

void Generator::dfaRow(DFARow const &row, size_t &index, ostream &out, 
                        vector<RuleFlagCount> &rfc)
{
    out << "    {";

    dfaTransitions(row, out);

    out << "  ";

    dfaRFCs(row, out, rfc);

    out << "},  // " << index++ << '\n';
}
