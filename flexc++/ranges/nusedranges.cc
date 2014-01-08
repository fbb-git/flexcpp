#include "ranges.ih"

size_t Ranges::nUsedRanges() const
{
    return d_nRanges - count(d_usedRanges, d_usedRanges + d_nRanges, false);
}
