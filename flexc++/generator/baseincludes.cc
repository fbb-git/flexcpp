#include "generator.ih"

void Generator::baseIncludes(ostream &out) const
{
    bool interactive = d_options.interactive();

    if (interactive)
    {
        key(out);
        out << "#include <sstream>\n";
    }

    if (!d_debug && !d_options.hasNames())
        return;

    if (!interactive)
    {
        key(out);
        out << "#include <sstream>\n";
    }

    out <<  "#include <set>\n"
            "#include <iomanip>\n";
}
