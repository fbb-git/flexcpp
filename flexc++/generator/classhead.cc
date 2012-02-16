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
        "{\n";

    out <<
        "    public:\n"
        "        explicit " << name << "(std::istream &in = std::cin,\n"
        "                                std::ostream &out = std::cout);\n";

    if (not interactive)
        out << 
            "\n"
            "        " << name << "(std::string const &infile, "
                                            "std::string const &outfile);\n";
}
