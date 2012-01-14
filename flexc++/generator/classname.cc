#include "generator.ih"

void Generator::className(ostream &out) const
{
    key(out);

    out << "class " << d_options.className() << ": ";

    if (d_options.interactive())
        out << "private std::istringstream, ";

    out << "public " << d_options.className() << "Base\n";
}
