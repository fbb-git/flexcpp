#include "dfarow.ih"

// called from the DFARow constructor

void DFARow::insertFinAc(size_t stateIdx, DFARow &thisRow)
{
    State const &state = (*thisRow.d_states)[stateIdx];

    int rule = state.rule();

    if (rule == -1)             // not an LA rule
        return;

                                // get the rule information at thisRule
    Rule const &thisRule = (*thisRow.d_rules)[rule];

    auto finAcIter = find(thisRow.d_finAc.begin(), 
                       thisRow.d_finAc.end(), rule);

    if (finAcIter == thisRow.d_finAc.end())     // rule not yet entered
    {
        thisRow.d_finAc.push_back(FinAc(rule));
        finAcIter = thisRow.d_finAc.begin() + 
                                            thisRow.d_finAc.size() - 1;
    }

    // finAcIter now points at the FinAc record for the current DFA row

    size_t acceptState = thisRule.accept();
    if (acceptState == stateIdx)
        finAcIter->setAccept(0);

    size_t finalState = thisRule.finalState();
    if (finalState == stateIdx)
        finAcIter->setFinal(-1);
}




