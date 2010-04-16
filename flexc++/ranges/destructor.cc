#include "ranges.ih"

Ranges::~Ranges()
{
    delete[] d_ranges;
    delete[] d_used;
}
