#include "generator.ih"

    // show one row of a DFA
void Generator::dfaRow(DFARow const &row, size_t &index, ostream &out, 
                        vector<RuleFlag> &rfs)
{
    out << "    {";

    dfaTransitions(row, out);       // show the transitions

    out << "   ";                   // extra space to separate R / F

    dfaRFs(row, out, rfs);

    out << "},  // " << index++ << '\n';
}
