#include "generator.ih"

void Generator::accCount(ostream &out) const
{
    out <<
    "    accCount(" << d_rules.size() << ")\n";
}
