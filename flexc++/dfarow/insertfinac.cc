#include "dfarow.ih"

// called from the DFARow constructor for each of the states defining a dfa
// row, passing the successive statIdx values of the states to this function

void DFARow::insertFinAc(size_t stateIdx, DFARow &thisRow)
{
    State const &state = (*thisRow.d_states)[stateIdx];

    int rule = state.rule();    // to which rule does this state belong?

    if (rule == -1)             // not an LA rule: no further action required
        return;

                                // directly access the LA-rule's details
    Rule const &thisRule = (*thisRow.d_rules)[rule];

                                // store the FinAc info if it's not yet there
    auto finAcIter = find(thisRow.d_finAc.begin(), 
                       thisRow.d_finAc.end(), rule);

    if (finAcIter == thisRow.d_finAc.end())     // add a FinAc element
    {                                           // if not yet there
        thisRow.d_finAc.push_back(FinAc(rule));
        finAcIter = thisRow.d_finAc.begin() + thisRow.d_finAc.size() - 1;
    }

    // At this point finAcIter refers to the FinAc record for the current DFA
    // row and rule 'rule'

    // If the accepting state (i.e., the state at the LOP operator) equals the 
    // current state index then set the accept count of that state to 0.
    if (thisRule.accept() == stateIdx)
    {
        finAcIter->setAccept(0);
        finAcIter->setLOP();            // uses the LOP
    }

    if (thisRule.finalState() == stateIdx)  // this is a final state
        finAcIter->setFinal();
}




