#include "ranges.ih"

void Ranges::finalizeState(State &state, size_t *ranges)
{
    switch (size_t type = state.type())
    {
        case State::CHARSET:
            charsetToRanges(state.data(), ranges);
        break;

        case State::STRING:
                             // TO DO
        break;
        default:
            if (type < State::UNDETERMINED__)
                type = ranges[type];
        break;
    }

}
