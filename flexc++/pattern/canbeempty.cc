#include "pattern.ih"

bool Pattern::canBeEmpty(States const &states) const
{
    return 
        (fixedLength() && length() == 0)
        or
        empty(states, d_pair.first);
}
