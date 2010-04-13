#include "decimal.ih"

spSemVal Decimal::range(SemVal &lower, SemVal &upper)
{
    spSemVal ret {new Decimal(downCast<Decimal>(lower).d_lower,
                                downCast<Decimal>(upper).d_upper)};
    return ret;
}
