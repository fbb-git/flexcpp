#include "generator.hh"

void Generator::key(ostream &out) const
{
    out << indent << "// $insert " << d_key << '\n';
}
