#include "generator.ih"

void Generator::declarations()
{
    d_out.close();
    Msg::open(d_out, "DECLARE.h");

    d_out << 
            "    typedef struct AcceptInfo\n"
            "    {\n"
            "        char   type;\n"
            "        size_t rule;\n"
            "    };\n"
            "\n"
            "    enum class Begin\n"
            "    {\n";

    for_each(d_startStates.begin(), d_startStates.end(), 
            FnWrap::unary(outStartState, d_out));

    d_out << 
            "    };\n"
            "\n"
            "    static size_t  const s_ranges[];\n"
            "    static size_t  const s_rangeOfBOL;\n"
            "    static size_t  const s_rangeOfEOF;\n"
            "    static size_t  const s_dfa[][" << dfaCols() << "];\n"
            "    static AcceptInfo const s_accept[];\n"
            "    static std:::unordered_map<Begin, size_t (*)[" << 
                       dfaCols() << "]> const s_dfaHash;\n";
}
