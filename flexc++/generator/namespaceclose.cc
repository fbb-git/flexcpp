#include "generator.hh"

void Generator::namespaceClose(std::ostream &out) const
{
    if (d_options.nameSpace().empty())
        return;

    key(out);
    out <<  "}\n";
}
