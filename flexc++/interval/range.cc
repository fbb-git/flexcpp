#include "interval.ih"

Interval Interval::range(string const &lower, string const &upper)
{
    Interval ret {A2x(lower), A2x(upper)};
    return ret;
}
