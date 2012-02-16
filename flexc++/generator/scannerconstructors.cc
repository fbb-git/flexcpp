#include "generator.ih"

void Generator::scannerConstructors(ostream &out) const
{
    key(out);

    std::string const &name = d_options.className();

    if (d_options.interactive())
        out << 
            "inline " << name << "::" << name << 
                                "(std::istream &in, std::ostream &out)\n"
            ":\n"
            "    " << name << "Base(in, out, this)\n"
            "{}\n";
    else
        out <<
            "inline " << name << "::" << name << 
                                "(std::istream &in, std::ostream &out)\n"
            ":\n"
            "    " << name << "Base(in, out)\n"
            "{}\n"
            "\n"
            "inline " << name << "::" << name << "(std::string const &infile,"
                                            " std::string const &outfile)\n"
            ":\n"
            "    " << name << "Base(infile, outfile)\n"
            "{}\n";
}
