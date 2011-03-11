#include "generator.ih"

void Generator::baseClassH(ostream &out) const
{
    key(out);
    out << "#include \"" << d_options.baseclassHeaderName() << "\"\n";
}
