#include "ranges.ih"

void Ranges::determineSubsets()
{
    for_each(d_states.begin(), d_states.end(), 
                FnWrap::unary(inspectState, *this));
}
