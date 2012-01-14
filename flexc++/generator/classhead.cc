#include "generator.ih"

void Generator::classHead(ostream &out) const
{
    key(out);

    std::string const &name = d_options.className();
    bool interactive = d_options.interactive();

    out << "class " << name << ": ";

    if (interactive)
        out << "private std::istringstream, ";

    out << "public " << name << "Base\n"
        "{\n"
        "    public:\n";

    if (interactive)
        out << 
            "        explicit " << name << "(std::ostream &out = std::cout);"
                                                                        "\n";
    else
        out << 
            "        explicit " << name << "(std::istream &in = std::cin,\n"
            "                                std::ostream &out = std::cout);"
                                                                        "\n"
            "\n"
            "        " << name << "(std::string const &infile, "
                                            "std::string const &outfile);\n";
}
