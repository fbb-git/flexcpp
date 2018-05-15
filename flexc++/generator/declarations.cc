#include "generator.ih"

void Generator::declarations(ostream &out) const
{
    out <<
        "\n"
        "    int     const (*d_dfaBase_)[" << dfaCols() << "];\n"
        "\n"
        "    static int     const s_dfa_[][" << dfaCols() << "];\n"
        "    static int     const (*s_dfaBase_[])[" << dfaCols() <<"];\n"
        "    enum: bool { s_interactive_ = " <<
                boolalpha << d_options.interactive() << " };\n"

        "    enum: size_t {\n"
        "        s_rangeOfEOF_           = " << d_ranges.rangeOfEOF() << 
                                                                        ",\n"
        "        s_finIdx_               = " << dfaCols() - 2 << ",\n"
        "        s_nRules_               = " << d_rules.size() << ",\n"
        "        s_maxSizeofStreamStack_ = " << d_options.maxDepth() << "\n"
        "    };\n"
        ;
}






