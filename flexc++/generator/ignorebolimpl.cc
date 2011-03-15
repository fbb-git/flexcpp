#include "generator.ih"

void Generator::ignoreBOLimpl(ostream &out) const
{
    if (d_useBOL)
    {
        key(out);
        out << 
            "    void ScannerBase::ignoreBOL__()\n"
            "    {\n";

        if (d_debug)
            out << 
            "        if (d_debug__)\n"
            "            s_out__  << \"IGNORE_BOL\\n\";\n";

        out <<
            "        d_startsAtBOL = false;\n"
            "    }\n";
    }
}




