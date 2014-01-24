#include "generator.ih"

    // show one row of a DFA
void Generator::dfaRow(DFARow const &row, size_t &index, ostream &out)
{
    out << "    {";

    dfaTransitions(row, out);       // show the transitions

    out << "   ";                   // extra space to separate states from
                                    // the rules

    dfaRules(row, out);             // show the rules, matched in this state

    out << "},  // " << index++ << '\n';
}
