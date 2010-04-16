#include "ranges.ih"

Ranges::Ranges(States &states, size_t size)
:
    d_ranges(new size_t[size]),
    d_size(size),
    d_subsets(0),
    d_bol(0),
    d_eof(0),
    d_states(states),
    d_used(0)
{
    fill(d_ranges, d_ranges + d_size, 0);
}
