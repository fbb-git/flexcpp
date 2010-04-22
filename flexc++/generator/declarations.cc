#include "generator.ih"

void Generator::declarations()
{
    d_out.close();
    Msg::open(d_out, "DECLARE");

    d_out << 
            "    struct Accept\n"
            "    {\n"
            "        int LAsize;\n"
            "        int lastMatchSize;\n"
            "    };\n"
            "\n"
            "    enum class Begin\n"
            "    {\n";

    for_each(d_startStates.begin(), d_startStates.end(), 
            FnWrap::unary(outStartState, d_out));

    d_out << 
        "    };\n"
        "\n"
        "    struct HashBegin\n"
        "    {\n"
        "        size_t operator()(Begin begin) const\n"
        "        {\n"
        "            return static_cast<size_t>(begin);\n"
        "        }\n"
        "    };\n"
        "\n"
        "    int const (*d_dfa)[" << dfaCols() << "];\n"
        "    Accept d_accept[" << d_nRules << "];\n"
        "\n"
        "    static bool    const s_interactive = " <<
                boolalpha << Options::instance().interactive() << ";\n"
        "    static size_t  const s_finalIdx = " << dfaCols() - 4 << ";\n"
        "    static size_t  const s_acceptIdx = " << dfaCols() - 2 << ";\n"
        "    static size_t  const s_acceptSize = " << d_nRules << ";\n"
        "    static size_t  const s_ranges[];\n"
        "    static size_t  const s_rangeOfBOL = " << 
                                        (d_ranges.rangeOfEOF() + 1) << ";\n"
        "    static size_t  const s_rangeOfEOF = " << d_ranges.rangeOfEOF() 
                                                                    << ";\n"
        "    static int     const s_dfa[][" << dfaCols() << "];\n"
        "    static size_t const s_accept[];\n"
        "    static size_t const s_final[];\n"
        "    static std::vector<size_t> const s_startStates[" << 
                                            d_startStates.size() << "];\n"
        "    static std::unordered_map<Begin, int const (*)[" << 
                   dfaCols() << "], HashBegin>\n"
        "           const s_dfaHash;\n";
}

