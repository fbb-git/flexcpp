#include "usage.ih"

Usage::Usage(Usage const &&tmp)
:
    d_usage(tmp.d_usage),
    d_size(tmp.d_size),
    d_subsets(tmp.d_subsets)
{
    const_cast<Usage &>(tmp).d_usage = 0;
}
