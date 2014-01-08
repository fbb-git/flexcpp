#include "generator.ih"

void Generator::startCondNames(ostream &out) const
{
    key(out);

    for (auto it = d_rules.begin(), end = d_rules.endUserSC(); it != end; ++it)
        out <<  indent << (*it).name() << ",\n";
}
