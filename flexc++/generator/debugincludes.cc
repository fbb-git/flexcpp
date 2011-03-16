#include "generator.ih"

void Generator::debugIncludes(ostream &out) const
{
    if (!d_debug && !d_options.hasNames())
        return;

    key(out);

    out <<  "#include <set>\n"
            "#include <sstream>\n"
            "#include <iomanip>\n";
}
