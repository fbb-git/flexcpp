#include "generator.ih"

void Generator::startCondNames(ostream &out) const
{
    out << setw(12) << "" << "INITIAL";

    for (auto it = d_rules.begin(), end = d_rules.end(); it != end; ++it)
    {
        string const &name = (*it).first;
        if (name != "INITIAL")
            out << ",\n" << setw(12) << "" << (*it).first;
    }

    out << '\n';
}
