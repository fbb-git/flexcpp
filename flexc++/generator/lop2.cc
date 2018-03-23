#include "generator.ih"

void Generator::lop2(ostream &out) const
{
    out <<
"void " << d_baseclassScope << R"(lop2_()   // matched the tail
{
    d_lopEnd = d_lopTail;                   // read the head
    d_lopIter = d_lopMatched.begin();
)";

    if (d_debug)
        out << 
R"(
    if (s_debug_)
        s_out_ << "lop2_ matched tail `" << d_matched << "\'\n" << dflush_;
)";
                                            
        out << 
R"(
    begin(SC(d_startCondition + 1));        // switch to the head-matching
}                                           // SC
)";

} // lop2
