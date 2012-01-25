#include "interval.ih"

Interval Interval::lowerBound(std::string const &lower)
{
    Interval ret(A2x(lower), numeric_limits<size_t>::max());
    return ret;
}
