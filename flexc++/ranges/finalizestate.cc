#include "ranges.ih"

// When BOL is encountered, increment the subsetcount.

void Ranges::finalizeState(State &state)
{
    switch (size_t type = state.type())
    {
        case CHARSET:
            charsetToRanges(state.data(), d_alphabet);
        break;

        case EOF_:
            state.setType(d_eof);
        break;

        default:
            if (type < UNDETERMINED_)
                state.setType(d_alphabet[type]);
        break;
    }
}

