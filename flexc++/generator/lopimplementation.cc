#include "generator.hh"

void Generator::lopImplementation(ostream &out) const
{
    if (not d_lopUsed)
        return;

    key(out);

    if (d_rules.hasFixedTailLOPrules())
        lopf(out);

    if (d_rules.hasVariableTailLOPrules())
    {
        lop1(out);
        lop2(out);
        lop3(out);
        lop4(out);

        getLOP(out);
    }
}

