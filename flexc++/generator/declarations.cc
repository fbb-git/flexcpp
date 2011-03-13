#include "generator.ih"

void Generator::declarations(ostream &out) const
{
//    d_out << 
//            "    struct Accept\n"
//            "    {\n"
//            "        int headSize;\n"
//            "        int lastMatchSize;\n"
//            "    };\n"
//            "\n"
//            "    enum class Begin\n"
//            "    {\n";
//
//    for_each(d_startStates.begin(), d_startStates.end(), 
//            FnWrap::unary(outStartState, d_out));
//
//    d_out << 
//        "    };\n"
//        "\n"
//        "    struct HashBegin\n"
//        "    {\n"
//        "        size_t operator()(Begin begin) const\n"
//        "        {\n"
//        "            return static_cast<size_t>(begin);\n"
//        "        }\n"
//        "    };\n"
//        "\n"
//        "    int const (*d_dfa)[" << dfaCols() << "];\n"
//        "    Accept d_accept[" << d_rules.size() << "];\n"
//        "\n"


    out <<
        "    int     const (*d_dfaBase)[" << dfaCols() << "];\n"
        "\n"
        "    static bool    const s_interactive = " <<
                boolalpha << d_options.interactive() << ";\n"
        "    static int     const s_dfa[][" << dfaCols() << "];\n"
        "    static int     const (*s_dfaBase[])[" << dfaCols() <<"];\n"
        "    static size_t  const s_rangeOfBOL = " << 
                                        (d_ranges.rangeOfEOF() + 1) << ";\n"
        "    static size_t  const s_rangeOfEOF = " << d_ranges.rangeOfEOF() <<
                                                                        ";\n"
        "    static size_t  const s_finacIdx = " << dfaCols() - 2 << ";\n"
        "    static size_t  const s_nRules = " << d_rules.size() << ";\n"
        ;


//        "    static size_t  const s_finalIdx = " << dfaCols() - 4 << ";\n"
//        "    static size_t  const s_acceptSize = " << d_rules.size() << ";\n"
//        "    static std::vector<size_t> const s_startStates[" << 
//                                            d_startStates.size() << "];\n"
//        "    static std::unordered_map<Begin, int const (*)[" << 
//                   dfaCols() << "], HashBegin>\n"
//        "           const s_dfaHash;\n";
}


