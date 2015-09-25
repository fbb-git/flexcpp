#include "generator.ih"

void Generator::inlineLexFunction(std::ostream &out) const
{
    if (not d_options.interactive())
    {
        key(out);

        out << 
            "inline int " << d_options.className() << "::" << 
                                        d_options.lexFunctionName() << "()\n"
            "{\n"
            "    return lex__();\n"
            "}\n";
    }
}
