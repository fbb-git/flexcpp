#include "generator.ih"

void Generator::declarations(ostream &out) const
{
    out <<
        "\n"
        "    int     const (*d_dfaBase__)[" << dfaCols() << "];\n"
        "\n"
        "    static int     const s_dfa__[][" << dfaCols() << "];\n"
        "    static int     const (*s_dfaBase__[])[" << dfaCols() <<"];\n"
        "    enum: bool { s_interactive__ = " <<
                boolalpha << d_options.interactive() << " };\n"

        "    enum: size_t {\n"
        "        s_rangeOfEOF__           = " << d_ranges.rangeOfEOF() << 
                                                                        ",\n"
        "        s_finIdx__               = " << dfaCols() - 2 << ",\n"
        "        s_nRules__               = " << d_rules.size() << ",\n"
        "        s_maxSizeofStreamStack__ = " << d_options.maxDepth() << "\n"
        "    };\n"
        ;
}






