#include "generator.ih"

void Generator::rfcs(ostream &out) const
{
    string const &className = d_options.className();

    out << 
        "int const " << className << "Base::s_rfc[][3] =\n"
        "{\n"
        "//     R  F  C\n";

    size_t idx = 0;
    for_each(d_rfc.begin(), d_rfc.end(), FnWrap::unary(outRFC, out, idx));
    out << "};";
}
