#include "generator.ih"

void Generator::lop1(ostream &out) const
{
    out <<
"void " << d_baseclassScope << R"(lop1__(int lopSC)
{
    d_lopMatched = d_matched;
    d_lopPending = d_input.nPending();

    d_lopEnd = d_lopMatched.end();
    d_lopTail = d_lopEnd - 1;
    d_lopIter = d_lopTail;
)";

    if (d_debug)
        out << 
R"(     
    if (s_debug__)
        s_out__ << "lop1__ received `" << )"
                                R"(d_lopMatched << "\'\n" << dflush__;
)";

    out << 
R"(
    d_get = &)" << d_baseclassScope << R"(getLOP;

    d_lopSC = d_startCondition;             // remember original SC
    begin(SC(lopSC));                       // activate the 
                                            // tail-matching SC
}
)";

} // lop1
