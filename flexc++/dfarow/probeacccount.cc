#include "dfarow.ih"

// called from the DFARow constructor for each of the States defining a dfa
// row, passing the successive stateIdx values of the states to this function

void DFARow::probeAccCount(size_t stateIdx, DFARow &thisRow)
{
    State const &state = (*thisRow.d_states)[stateIdx]; // state shorthand

    State::Flag flag = state.flag();

    if (flag == State::NO_LOP)  // Done unless a state of a rule using the LOP
        return;

    int rule = state.rule();    // To which rule does this state belong?

        // obtain the iterator to the AccCount object for `rule'
    auto accCountIter = find(thisRow.d_accCount.begin(), 
                             thisRow.d_accCount.end(), rule);

        // add an AccCount element if not yet there
    if (accCountIter == thisRow.d_accCount.end())     
        thisRow.d_accCount.push_back(AccCount(rule, flag));
    else
        accCountIter->addFlag(flag);
}








