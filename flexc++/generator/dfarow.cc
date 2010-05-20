#include "generator.ih"

void Generator::dfaRow(DFARow const &row, ostream &out, 
                        PVector &accept, vector<size_t> &final)
{
    out << "        {";

    dfaTransitions(row, out);
    dfaFinAcs(row, out, final);

    out << "'},\n";
}

