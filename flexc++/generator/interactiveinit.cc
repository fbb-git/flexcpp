#include "generator.hh"

void Generator::interactiveInit(ostream &out) const
{
    key(out);

    if (!d_options.interactive())
        out << 
            "    d_in(0),\n"
            "    d_input(new std::istream(in.rdbuf())),\n";
    else
        out <<
            "    d_in(&in),\n"
            "    d_line(new std::istringstream()),\n"
            "    d_input(new std::istream(d_line->rdbuf())),\n";
}

