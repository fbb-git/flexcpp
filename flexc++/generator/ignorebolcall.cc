#include "generator.ih"

void Generator::ignoreBOLcall(ostream &out) const
{
    if (d_useBOL)
    {
        key(out);
        out << indent << "ignoreBOL__();\n";
    }
}
