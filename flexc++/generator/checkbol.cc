#include "generator.ih"

void Generator::checkBOL(ostream &out) const
{
    if (d_useBOL)
    {
        key(out);
        out << 
            "    if (range == s_rangeOfBOL)\n"
            "    {\n"
            "        if (d_startsAtBOL)\n"
            "            return ActionType__::IGNORE_BOL;\n"
            "        d_startsAtBOL = true;\n"
            "    }\n";
    }
}
