#include "ranges.ih"

Ranges::Ranges(Ranges &&tmp)
:
    d_ranges(tmp.d_ranges),
    d_size(tmp.d_size),
    d_subsets(tmp.d_subsets),
    d_states(tmp.d_states),
    d_used(tmp.d_used)
{
    tmp.d_ranges = 0;
    tmp.d_used = 0;
}
