#include "dfa.ih"

void DFA::processLArule(LARule const &laRule, std::vector<DFARow> &rows)
{
    processRule(laRule.rule(), rows, 0, true, 0);
}
