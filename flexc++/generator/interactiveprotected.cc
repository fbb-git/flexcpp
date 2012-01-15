#include "generator.ih"

void Generator::interactiveProtected(ostream &out) const
{
    if (not d_options.interactive())
        return;

    key(out);

    out << "protected:\n";
}








