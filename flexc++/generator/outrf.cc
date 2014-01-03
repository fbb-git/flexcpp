#include "generator.ih"

void Generator::outRF(RuleFlag const &rf, ostream &out, size_t &idx)
{
    out << 
        "     {" << setw(2) << rf.d_rule << ',' << 
                    setw(2) << rf.d_flag << ',' << 
              "},  // " << idx++ << '\n';
}
