#include "generator.ih"

void Generator::interactiveLex(ostream &out) const
{
    if (!d_options.interactive())
        return;

    key(out);

    std::string const &name = d_options.className();

    out << 
        "bool " << d_baseclassScope << "interactiveLine()\n"
        "{\n"
        "    std::string line;\n"
        "\n"
        "    if (not std::getline(*d_in, line))\n"
        "        return false;\n"
        "\n"
        "    line += '\\n';\n"
        "    d_line->clear();\n"
        "    d_line->str(line);\n"
        "    switchStream_(*d_line, lineNr());\n"
        "\n"
        "    return true;\n"
        "}\n"
        "\n"
        "int " << name << "::" << d_options.lexFunctionName() << "()\n"
        "{\n"
        "    return lex_() != 0        ? d_token_ :\n"
        "           interactiveLine() ?   lex_()   :\n"
        "                                 0;\n"
        "}\n";
}
