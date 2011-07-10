#include "generator.ih"

void Generator::declarations(ostream &out) const
{
    out <<
        "\n"
        "    int     const (*d_dfaBase__)[" << dfaCols() << "];\n"
        "\n"
        "    static bool    const s_interactive__ = " <<
                boolalpha << d_options.interactive() << ";\n"
        "    static int     const s_dfa__[][" << dfaCols() << "];\n"
        "    static int     const (*s_dfaBase__[])[" << dfaCols() <<"];\n"

        "    static size_t  const s_rangeOfEOF__ = " << d_ranges.rangeOfEOF() <<
                                                                        ";\n"
        "    static size_t  const s_finacIdx__ = " << dfaCols() - 2 << ";\n"
        "    static size_t  const s_nRules__ = " << d_rules.size() << ";\n"
        ;
}






