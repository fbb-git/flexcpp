#include "ranges.ih"

void Ranges::inspectState(State const &state)
{
cerr << "   " << state << '\n';
    size_t type = state.type();
    
    if (type < UNDETERMINED__)
        add(type);
    else if (type == CHARSET)
        add(state.data().str());
}

