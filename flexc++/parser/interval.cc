#include "parser.ih"

spSemVal Parser::interval(SemVal &semval, SemVal &range)
{
    size_t lower = SemVal::downCast<Decimal>(range).lower();
    size_t upper = SemVal::downCast<Decimal>(range).upper();

    if (lower > upper)
        lineMsg() << " in {" << lower << ", " << upper << 
                    "}:  first value may not exceed second value" << err;

    spSemVal ret = PatternVal::interval(d_states, semval, lower, upper);

    return ret;
}
