#include "generator.ih"

void Generator::dfaRow(DFARow const &row, ostream &out, 
                        vector<FinAcInfo> &finAcs)
{
    out << "        {";

    dfaTransitions(row, out);
    dfaFinAcs(row, out, finAcs);

    out << "},\n";
}

