#include "ranges.hh"

// When BOL is encountered, increment the subsetcount.

void Ranges::finalizeState(State &state)
{
    switch (size_t type = state.type())
    {
        case CHARSET:
            charsetToRanges(state.data(), d_alphabet);
        break;

        case EOF__:
            state.setType(d_eof);
        break;

        default:
            if (type < UNDETERMINED__)
                state.setType(d_alphabet[type]);
        break;
    }
}

