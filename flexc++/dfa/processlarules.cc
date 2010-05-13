#include "dfa.ih"

    // process all rule values of dfa row 0
void DFA::processLArules()
{
    for_each(d_row[0].laRules().begin(), d_row[0].laRules().end(),
             FnWrap::unary(processLArule, d_row));
}
