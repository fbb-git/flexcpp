#include "generator.ih"

void Generator::lop2(ostream &out) const
{
    out <<
"void " << d_baseclassScope << R"(lop2__()   // matched the tail
{
    d_lopEnd = d_lopTail;                   // read the head
    d_lopIter = d_lopMatched.begin();
)";

    if (d_debug)
        out << 
R"(
    s_out__ << "lop2__ matched tail `" << d_matched << "\'\n" << dflush__;
)";
                                            
        out << 
R"(
    begin(SC(d_startCondition + 1));        // switch to the head-matching
}                                           // SC
)";

} // lop2
