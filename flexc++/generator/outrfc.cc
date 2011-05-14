#include "generator.ih"

void Generator::outRFC(RuleFlagCount const &rfc, ostream &out, size_t &idx)
{
    out << 
        "     {" << setw(2) << rfc.d_rule << ',' << 
                    setw(2) << rfc.d_flag << ',' <<
                    setw(2) << rfc.d_count << "},  // " << idx++ << '\n';
}
