#include "generator.ih"

void Generator::ruleAction(Rule const &rule, ostream &out, size_t &idx,
                                                        bool lineDirectives)
{
    Block const &block = rule.block();

    if (block.str().length())
    {
        out << 
            "        case " << idx << ":\n"
            "        {\n";

        if (lineDirectives)
            out <<  "#line " << block.line()  << " \"" << block.source() << 
                                                                    "\"\n";
        out << 
            "            " << block.str() << "\n"
            "        }\n"
            "        break;\n";
    }

    ++idx;
}
