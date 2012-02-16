#include "generator.ih"

void Generator::interactiveLex(ostream &out) const
{
    if (!d_options.interactive())
        return;

    key(out);

    std::string const &name = d_options.className();

    out << 
        "int " << name << "::" << d_options.lexFunctionName() << "()\n"
        "{\n"
        "    int token = lex__();\n"
        "\n"
        "    if (token != 0)\n"
        "        return token;\n"
        "\n"
        "    std::string line;\n"
        "\n"
        "    if (d_in__ == 0 || not std::getline(*d_in__, line))\n"
        "        return 0;\n"
        "\n"
        "    line += '\\n';\n"
        "    clear();\n"
        "    str(line);\n"
        "    switchStream__(*this);\n"
        "\n"
        "    return lex__();\n"
        "}\n";
}
