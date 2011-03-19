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

    auto finAcIter = find(thisRow.d_finAcInfo.begin(), 
                       thisRow.d_finAcInfo.end(), rule);

    if (finAcIter == thisRow.d_finAcInfo.end())     // rule not yet entered
    {
        thisRow.d_finAcInfo.push_back(FinAcInfo(rule));
        finAcIter = thisRow.d_finAcInfo.begin() + 
                                            thisRow.d_finAcInfo.size() - 1;
    }

    // finAcIter now points at the FinAcInfo record for the current DFA row

    size_t acceptState = thisRule.accept();
    if (acceptState == stateIdx)
        finAcIter->setAccept(0);

    size_t finalState = thisRule.finalState();
    if (finalState == stateIdx)
        finAcIter->setFinal(-1);
}




