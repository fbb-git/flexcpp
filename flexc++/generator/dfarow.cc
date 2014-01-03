#include "generator.ih"

void Generator::dfaRow(DFARow const &row, size_t &index, ostream &out, 
                        vector<RuleFlag> &rfs)
{
    out << "    {";

    dfaTransitions(row, out);

    out << "  ";

    dfaRFs(row, out, rfs);

    out << "},  // " << index++ << '\n';
}
