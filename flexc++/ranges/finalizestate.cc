#include "ranges.ih"

void Ranges::finalizeState(State &state, size_t *ranges)
{
    size_t type = state.type();

    if (type < State::UNDETERMINED__)
        state.setType(ranges[type]);

    else if (type == State::CHARSET)
        charsetToRanges(state.data(), ranges);
}
