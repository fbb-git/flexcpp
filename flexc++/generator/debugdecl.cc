#include "generator.ih"

void Generator::debugDecl(std::ostream &out) const
{
    if (!d_debug && !d_options.hasNames() && !d_debugStep)
        return;

    key(out);
    out << 
        "        size_t d_beginStep__;\n"
        "        size_t d_endStep__;\n"
        "        size_t d_step__;\n"
        "\n"
        "        static bool s_debug__;\n"
        "        static std::ostringstream s_out__;\n"
        "        static std::ostream &dflush__(std::ostream &out);\n";
}
