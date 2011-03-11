#include "generator.ih"

void Generator::namespaceOpen(std::ostream &out) const
{
    if (not d_options.nameSpace().empty())
    {
        key(out);
        out <<  "namespace " << d_options.nameSpace() << "\n"
                "{\n";
    }
}


