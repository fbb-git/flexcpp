#include "ranges.hh"

void Ranges::inspectState(State const &state)
{
    size_t type = state.type();
    
    if (type < UNDETERMINED__)
        add(type);
    else if (type == CHARSET)
        add(state.data().str());
}

