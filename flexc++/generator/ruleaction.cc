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

        istringstream actions(block.str());
        string line;
        while (getline(actions, line))
            out << setw(12) << ' ' << line << '\n';

        out << 
            "        }\n"
            "        break;\n";
    }
}
