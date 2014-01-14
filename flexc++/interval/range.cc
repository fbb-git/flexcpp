#include "interval.ih"

Interval Interval::range(string const &lower, string const &upper)
{
    Interval ret {stoul(lower), stoul(upper)};
    return ret;
}
