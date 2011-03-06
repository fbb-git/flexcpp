#include "generator.ih"

void Generator::dfaRow(DFARow const &row, size_t &index, ostream &out, 
                        vector<FinAcInfo> &finAcs)
{
    out << "        {";

    dfaTransitions(row, out);

    out << "  ";

    dfaFinAcs(row, out, finAcs);

    out << "},  // " << index++ << '\n';
}

