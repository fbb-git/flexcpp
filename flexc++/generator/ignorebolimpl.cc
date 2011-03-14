#include "generator.ih"

void Generator::ignoreBOLimpl(ostream &out) const
{
    if (d_useBOL)
    {
        key(out);
        out << 
            "    void ScannerBase::ignoreBOL__()\n"
            "    {\n"
            "//std::cout << \"IGNORE_BOL\\n\";\n"
            "        d_startsAtBOL = false;\n"
            "    }\n";
    }
}




