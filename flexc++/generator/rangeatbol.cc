#include "generator.ih"

void Generator::rangeAtBOL(ostream &out) const
{
    if (d_useBOL)
    {
        key(out);

        out << 
            indent << "case AT_BOL:\n" <<
            indent << "return s_rangeOfBOL;\n";
    }
}
