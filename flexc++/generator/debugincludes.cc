#include "generator.ih"

void Generator::debugIncludes(ostream &out) const
{
    if (not (d_debug))
        return;

    key(out);

    out <<  "#include <set>\n"
            "#include <sstream>\n"
            "#include <iomanip>\n";
}
