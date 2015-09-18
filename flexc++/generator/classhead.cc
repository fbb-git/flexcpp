#include "generator.hh"

void Generator::classHead(ostream &out) const
{
    key(out);

    std::string const &name = d_options.className();

    out << 
        "class " << name << ": public " << name << "Base\n"
        "{\n"
        "    public:\n"
        "        explicit " << name << "(std::istream &in = std::cin,\n"
        "                                std::ostream &out = std::cout);\n";

    if (not d_options.interactive())
        out << 
            "\n"
            "        " << name << "(std::string const &infile, "
                                            "std::string const &outfile);\n";
}
