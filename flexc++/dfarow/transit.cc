#include "dfarow.ih"

void DFARow::transit(size_t stateIdx,
                     DFARow &dfaRow, 
                     std::vector<std::set<size_t>> &stateSet,
                     std::set<size_t> const &rowSet,
                     size_t nRanges)
{
    set<size_t> nextSet;

    State const &state = dfaRow.d_states[stateIdx];
    size_t type = state.type();

    if (type == State::FINAL)
        dfaRow.setFinal(stateIdx);

    else if (type == State::CHARSET)
        // inspect for all chars in charset, if so addd next state(s)

    else
    {
        for (size_t idx = 0; idx++ != nRanges; )
        {
            if (type == idx)                            // plain char: transit
                nextSet.insert(idx);
        }
    }

    if (state.accept())
        dfaRow.setAccept(state.accept(), stateIdx);
}
