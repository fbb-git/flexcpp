#include "generator.ih"

void Generator::ruleAction(Block const &block, ostream &out, size_t idx) 
                                                                        const
{
    if (block.orAction())
        out << "        case " << idx << ":\n";
    else if (block.str().length())
    {
        out << 
            "        case " << idx << ":\n"
            "        {\n";

        if (d_lineDirectives)
            out << "#line " << block.lineNr()  << 
                               " \"" << block.filename() << "\"\n";
        out << 
            "            " << block.str() << "\n"
            "        }\n"
            "        break;\n";
    }
}
