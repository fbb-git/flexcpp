#include "ranges.ih"

Ranges::Ranges(Ranges const &&tmp)
:
    d_ranges(tmp.d_ranges),
    d_size(tmp.d_size),
    d_subsets(tmp.d_subsets),
    d_states(tmp.d_states),
    d_used(tmp.d_used)
{
    const_cast<Ranges &>(tmp).d_ranges = 0;
    const_cast<Ranges &>(tmp).d_used = 0;
}
