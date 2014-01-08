#include "ranges.ih"

void Ranges::clearUsed()
{
    fill(d_used, d_used + d_nRanges, false);
}
