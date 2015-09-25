#include "interval.ih"

Interval Interval::lowerBound(std::string const &lower)
{
    Interval ret(stoul(lower), max<size_t>());
    return ret;
}
