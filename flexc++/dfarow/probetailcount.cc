#include "dfarow.ih"

// called from the DFARow constructor for each of the States defining a dfa
// row, passing the successive stateIdx values of the states to this function

void DFARow::probeTailCount(size_t stateIdx, DFARow &thisRow)
{
    State const &state = (*thisRow.d_states)[stateIdx]; // state shorthand

    State::Flag flag = state.flag();

    if (flag == State::NO_LOP)  // Done unless a state of a rule using the LOP
        return;

    int rule = state.rule();    // To which rule does this state belong?

        // obtain the iterator to the TailCount object for `rule'
    auto tailCountIter = find(thisRow.d_tailCount.begin(), 
                             thisRow.d_tailCount.end(), rule);

        // add an TailCount element if not yet there
    if (tailCountIter == thisRow.d_tailCount.end())
        thisRow.d_tailCount.push_back(TailCount(rule, flag));
    else
        tailCountIter->addFlag(flag);

}








