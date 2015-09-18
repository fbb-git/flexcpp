#include "generator.hh"

void Generator::baseIncludes(ostream &out) const
{
    bool interactive = d_options.interactive();
    bool caseSensitive = d_options.caseSensitive();

    if (interactive || not caseSensitive)
        key(out);

    if (interactive)
        out << "#include <sstream>\n";

    if (not caseSensitive)
        out << "#include <cctype>\n";

    if (!d_debug)
        return;

    if (!interactive)
    {
        key(out);
        out << "#include <sstream>\n";
    }

    out <<  "#include <set>\n"
            "#include <iomanip>\n";
}
