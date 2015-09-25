#include "generator.ih"

void Generator::debugDecl(std::ostream &out) const
{
    if (not debugCodeRequired())
        return;

    key(out);
    out << 
        "        static bool s_debug__;\n"
        "        static std::ostringstream s_out__;\n"
        "        static std::ostream &dflush__(std::ostream &out);\n"
        "   private:\n";
}
