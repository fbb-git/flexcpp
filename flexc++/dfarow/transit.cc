#include "dfarow.ih"

void DFARow::transit(size_t stateIdx, DFARow &thisRow,
                                      size_t rangeChar,
                                      StateSet &nextSet)
{
    State const &state = (*thisRow.d_states)[stateIdx];
    size_t type = state.type();

    if (state.accept())
        thisRow.setAccept(state.accept(), stateIdx);

    if (type == State::FINAL)
        thisRow.setFinal(stateIdx);
    else if (type != State::CHARSET || state.contains(rangeChar))
        nextSet.insert(stateIdx);
}
