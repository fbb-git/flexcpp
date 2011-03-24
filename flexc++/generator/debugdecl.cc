#include "generator.ih"

void Generator::debugDecl(std::ostream &out) const
{
    if (!d_debug && !d_options.hasNames() && !d_debugStep)
        return;

    key(out);
    out << 
        "        static bool s_debug__;\n"
        "        static std::ostringstream s_out__;\n"
        "        static std::ostream &dflush__(std::ostream &out);\n"
        "   private:\n";
}
