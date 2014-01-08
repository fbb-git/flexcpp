#include "ranges.ih"

void Ranges::clearUsedRanges()
{
    fill(d_usedRanges, d_usedRanges + d_nRanges, false);
}
