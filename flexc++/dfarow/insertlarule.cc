#include "dfarow.ih"

void DFARow::insertLARule(size_t stateIdx, DFARow &thisRow)
{
    State const &state = (*thisRow.d_states)[stateIdx];

    int rule = state.rule();

    if (rule == -1)             // not an LA rule
        return;

    Rule const &thisRule = (*thisRow.d_rules)[rule];

    auto iter = find(thisRow.d_LARule.begin(), thisRow.d_LARule.end(), rule);

    if (iter == thisRow.d_LARule.end())     // rule not yet entered
    {
        thisRow.d_LARule.push_back(LARule(rule));
        iter = thisRow.d_LARule.begin() + thisRow.d_LARule.size() - 1;
    }

    size_t acceptState = thisRule.accept();
    if (acceptState == stateIdx)
        iter->setAccept(stateIdx);

    size_t finalState = thisRule.finalState();
    if (finalState == stateIdx)
        iter->setFinal(-1);
}


