#include "decimal.ih"

spSemVal Decimal::lowerBound(SemVal &lower)
{
    spSemVal ret {new Decimal(downCast<Decimal>(lower).d_lower, UINT_MAX)};
    return ret;
}
