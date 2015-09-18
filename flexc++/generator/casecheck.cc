#include "generator.hh"

void Generator::caseCheck(ostream &out) const
{
    if (d_options.caseSensitive())
        return;

    key(out);

    out << 
        "    ch = tolower(ch);\n"
        "\n";
}
