#include "generator.ih"

void Generator::ruleAction(Rule const &rule, ostream &out, 
                                                                size_t &idx)
{
    string const &actionCode = rule.action();

    if (actionCode.length())
    {
        out << 
            "        case " << idx << ":\n"
            "        {\n" <<
            "            " << actionCode << "\n"
            "        }\n"
            "        break;\n";
    }

    ++idx;
}
