#include "ranges.ih"

void Ranges::determineSubsets()
{
    for_each(d_states.begin(), d_states.end(), 
                FnWrap::unary(inspectState, *this));

    for (size_t idx = 0, last = UINT_MAX, count = 0; idx < 256; ++idx)
    {
        size_t &current = d_ranges[idx];

        if (current == last)
            current = count;
        else
        {
            last = current;
            current = ++count;
        }
    }
}
