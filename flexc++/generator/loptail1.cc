#include "generator.ih"

    // called from flexc++.cc skeleton
void Generator::lopTail1(std::ostream &out) const
{
    if (not d_lopUsed)
        return;

    key(out);
    out << "    d_lopTail1 = ch;\n";
}
