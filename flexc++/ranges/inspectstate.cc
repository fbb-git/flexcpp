#include "ranges.ih"

void Ranges::inspectState(State const &state, Ranges &ranges)
{
    switch (size_t type = state.type())
    {
        case State::STRING:
        case State::CHARSET:
            ranges.add(type == State::CHARSET ? ORDERED : NOT_ORDERED,
                      SemVal::downCast<StateString>(state.data()).str());
        break;

        default:
            if (type < State::UNDETERMINED__)
                ranges.add(type);
        break;
    }
}
