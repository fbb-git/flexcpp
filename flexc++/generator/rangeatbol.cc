#include "generator.ih"

void Generator::rangeAtBOL(ostream &out) const
{
    if (d_useBOL)
    {
        key(out);

        out << 
            "        case AT_BOL:\n" 
            "        return s_rangeOfBOL;\n";
    }
}
