#include "dfarow.ih"

// called from the DFARow constructor

void DFARow::insertFinAcInfo(size_t stateIdx, DFARow &thisRow)
{
    State const &state = (*thisRow.d_states)[stateIdx];

    int rule = state.rule();

    if (rule == -1)             // not an LA rule
        return;

                                // get the rule information at thisRule
    Rule const &thisRule = (*thisRow.d_rules)[rule];

    auto LAiter = find(thisRow.d_finAcInfo.begin(), 
                       thisRow.d_finAcInfo.end(), rule);

    if (LAiter == thisRow.d_finAcInfo.end())     // rule not yet entered
    {
        thisRow.d_finAcInfo.push_back(FinAcInfo(rule));
        LAiter = thisRow.d_finAcInfo.begin() + thisRow.d_finAcInfo.size() - 1;
    }

    // LAiter now points at the FinAcInfo record for the current DFA row

    size_t acceptState = thisRule.accept();
    if (acceptState == stateIdx)
        LAiter->setAccept(0);

    size_t finalState = thisRule.finalState();
    if (finalState == stateIdx)
        LAiter->setFinal(-1);
}




