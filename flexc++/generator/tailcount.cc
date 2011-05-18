#include "generator.ih"

void Generator::tailCount(ostream &out) const
{
    out <<
    "    d_tailCount(" << d_rules.size() << ", UINT_MAX),\n";
}
