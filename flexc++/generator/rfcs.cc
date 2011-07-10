#include "generator.ih"

void Generator::rfcs(ostream &out) const
{
    string const &className = d_options.className();

    out << 
        "size_t const " << className << "Base::s_rfc__[][3] =\n"
        "{\n"
        "//     R  F  C\n";

    size_t idx = 0;
    for_each(
        d_rfc.begin(), d_rfc.end(),
        [&](RuleFlagCount const &rfc)
        {
            outRFC(rfc, out, idx);
        }
    );
    out << "};";
}
