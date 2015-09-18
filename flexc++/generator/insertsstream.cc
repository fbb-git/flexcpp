#include "generator.hh"

void Generator::insertSstream(ostream &out) const
{
    key(out);

    out << "#include <sstream>\n";
}
