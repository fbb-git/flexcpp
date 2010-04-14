#include "ranges.ih"

void Ranges::inspectState(State const &state, Ranges &ranges)
{
    size_t type = state.type();
    
    if (type < State::UNDETERMINED__)
        ranges.add(type);
    else if (type == State::CHARSET)
        ranges.add(SemVal::downCast<StateString>(state.data()).str());
}
