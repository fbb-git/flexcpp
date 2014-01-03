#include "generator.ih"

void Generator::outRF(RuleFlag const &rf, ostream &out, size_t &idx)
{
    out << 
        "     {" << setw(2) << rfc.d_rule << ',' << 
                    setw(2) << rfc.d_flag << ',' << 
              "},  // " << idx++ << '\n';
}
