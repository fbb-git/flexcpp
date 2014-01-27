#include "generator.ih"

void Generator::lop3(ostream &out) const
{
    out <<
"inline void " << d_baseclassScope << R"(lop3__() // catch-all handler
{
    d_lopIter = --d_lopTail;                // increase the tail, try again
)";

    if (d_debug)
        out <<
R"(
    if (s_debug__)
        s_out__ << "lop3__: trying to match tail `" << 
               std::string(d_lopIter, d_lopEnd) << "'\n" << dflush__;
)";

    out << 
"}\n";

}   // lop3
