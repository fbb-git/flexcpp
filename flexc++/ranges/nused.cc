#include "ranges.ih"

size_t Ranges::nUsed() const
{
    return d_subsets - count(d_used, d_used + d_subsets, false);
}
