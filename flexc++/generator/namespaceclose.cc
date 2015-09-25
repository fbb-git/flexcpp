#include "generator.ih"

void Generator::namespaceClose(std::ostream &out) const
{
    if (d_options.nameSpace().empty())
        return;

    key(out);
    out <<  "}\n";
}
