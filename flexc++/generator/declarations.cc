#include "generator.ih"

void Generator::declarations(ostream &out) const
{
    out <<
        "\n"
        "    int     const (*d_dfaBase)[" << dfaCols() << "];\n"
        "\n"
        "    static bool    const s_interactive = " <<
                boolalpha << d_options.interactive() << ";\n"
        "    static int     const s_dfa[][" << dfaCols() << "];\n"
        "    static int     const (*s_dfaBase[])[" << dfaCols() <<"];\n"

        "    static size_t  const s_rangeOfEOF = " << d_ranges.rangeOfEOF() <<
                                                                        ";\n"
        "    static size_t  const s_finacIdx = " << dfaCols() - 2 << ";\n"
        "    static size_t  const s_nRules = " << d_rules.size() << ";\n"
        ;
}






