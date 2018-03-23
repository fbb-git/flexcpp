#include "generator.ih"

void Generator::debugDecl(std::ostream &out) const
{
    if (not debugCodeRequired())
        return;

    key(out);
    out << 
        "        static bool s_debug_;\n"
        "        static std::ostringstream s_out_;\n"
        "        static std::ostream &dflush_(std::ostream &out);\n"
        "   private:\n";
}
