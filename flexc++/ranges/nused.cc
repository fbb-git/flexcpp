#include "ranges.ih"

size_t Ranges::nUsed() const
{
    return d_nRanges - count(d_used, d_used + d_nRanges, false);
}
