#include "ranges.ih"

void Ranges::finalizeState(State &state, Ranges &obj)
{
    switch (size_t type = state.type())
    {
        case State::CHARSET:
            charsetToRanges(state.data(), obj.d_ranges);
        break;

        case State::BOL:
            if (obj.d_bol == 0)
                obj.d_bol = ++obj.d_subsets;
            state.setType(obj.d_bol);
        break;

        case State::EOF__:
            if (obj.d_eof == 0)
                obj.d_eof = ++obj.d_subsets;
            state.setType(obj.d_eof);
        break;

        default:
            if (type < State::UNDETERMINED__)
                state.setType(obj.d_ranges[type]);
        break;
    }
}

