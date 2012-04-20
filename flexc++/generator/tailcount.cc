#include "generator.ih"

void Generator::tailCount(ostream &out) const
{
    out <<
    "    d_tailCount(" << d_rules.size() << ", std::numeric_limits<size_t>::max()),\n";
}
