#include "generator.ih"

void Generator::debugDecl(std::ostream &out) const
{
    if (!d_debug)
        return;

    key(out);
    out << 
        "        bool d_debug__;\n"
        "        size_t d_beginStep__;\n"
        "        size_t d_endStep__;\n"
        "        size_t d_step__;\n"
        "\n"
        "        static std::ostringstream s_out__;\n"
        "        static std::ostream &dflush__(std::ostream &out);\n";
}


//      "        std::string symbol__(int value) const;\n"
//      "        std::string stype__(char const *pre, STYPE__ const &semVal,\n"
//      "                            char const *post = \"\") const;\n"
