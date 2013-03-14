#include "generator.ih"

void Generator::interactiveDecl(ostream &out) const
{
    key(out);

    if (d_options.interactive())
        out << "        bool                interactiveLine();\n";
}

