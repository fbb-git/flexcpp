#include "generator.ih"

void Generator::ignoreBOLaction(ostream &out) const
{
    if (d_useBOL)
    {
        key(out);
        out << 
            "    if (d_startsAtBOL)\n"
            "        return ActionType__::PUSH_FRONT;\n";
    }
}
