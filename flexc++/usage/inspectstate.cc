#include "usage.ih"

void Usage::inspectState(State const &state, Usage &usage)
{
    switch (size_t type = state.type())
    {
        case State::STRING:
        case State::CHARSET:
            usage.add(type == State::CHARSET ? ORDERED : NOT_ORDERED,
                      SemVal::downCast<StateString>(state.data()).str());
        break;

        default:
            if (type < State::UNDETERMINED__)
                usage.add(type);
        break;
    }
}
