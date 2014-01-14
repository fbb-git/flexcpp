#include "generator.ih"

    // called from flexc++.cc skeleton
void Generator::lop1stTail(std::ostream &out) const
{
    if (not d_lopUsed)
        return;

    key(out);
    out << "    d_lop1stTail = ch;\n";
}
