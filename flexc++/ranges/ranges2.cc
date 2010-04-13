#include "usage.ih"

Usage::Usage(Usage const &other)
:
    d_usage(new size_t[other.d_size]),
    d_size(other.d_size),
    d_subsets(other.d_subsets)
{
    copy(other.d_usage, other.d_usage + d_size, d_usage);
}
