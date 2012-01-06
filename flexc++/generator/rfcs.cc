#include "generator.ih"

void Generator::rfcs(ostream &out) const
{
    string const &className = d_options.className();

    out << 
        "size_t const " << className << "Base::s_rfc__[][3] =\n"
        "{\n"
        "//     R  F  C\n";

    size_t idx = 0;

    for (auto &rfc: d_rfc)
        outRFC(rfc, out, idx);

    out << "};";
}
