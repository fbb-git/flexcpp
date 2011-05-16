#include "generator.ih"

void Generator::accCount(ostream &out) const
{
    out <<
    "    d_accCount(" << d_rules.size() << ", UINT_MAX),\n";
}
