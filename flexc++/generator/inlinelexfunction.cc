#include "generator.ih"

void Generator::inlineLexFunction(std::ostream &out) const
{
    key(out);

    if (not d_options.interactive())
        out << 
            "inline int " << d_options.className() << "::" << 
                                        d_options.lexFunctionName() << "()\n"
            "{\n"
            "    return lex__();\n"
            "}\n";
}
