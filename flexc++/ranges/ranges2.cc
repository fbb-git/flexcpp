#include "ranges.ih"

Ranges::Ranges(Ranges const &other)
:
    d_ranges(new size_t[other.d_size]),
    d_size(other.d_size),
    d_subsets(other.d_subsets),
    d_states(other.d_states),
    d_used(new bool[other.d_subsets])
{
    copy(other.d_ranges, other.d_ranges + d_size, d_ranges);
    copy(other.d_used, other.d_used + d_subsets, d_used);
}
