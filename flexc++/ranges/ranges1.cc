#include "usage.ih"

Usage::Usage(size_t size)
:
    d_usage(new size_t[size]),
    d_size(size),
    d_subsets(0)
{
    fill(d_usage, d_usage + d_size, 0);
}
