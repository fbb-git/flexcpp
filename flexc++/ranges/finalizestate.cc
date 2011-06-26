#include "ranges.ih"

// When BOL is encountered, increment the subsetcount.

void Ranges::finalizeState(State &state)
{
    switch (size_t type = state.type())
    {
        case State::CHARSET:
            charsetToRanges(state.data(), d_ranges);
        break;

        case State::EOF__:
            state.setType(d_eof);
        break;

        default:
            if (type < State::UNDETERMINED__)
                state.setType(d_ranges[type]);
        break;
    }
}

