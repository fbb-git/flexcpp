#include "generator.ih"

void Generator::lop3(ostream &out) const
{
    out <<
"inline void " << d_baseclassScope << R"(lop3_() // catch-all handler
{
    d_lopIter = --d_lopTail;                // increase the tail, try again
)";

    if (d_debug)
        out <<
R"(
    if (s_debug_)
        s_out_ << "lop3_: trying to match tail `" << 
               std::string(d_lopIter, d_lopEnd) << "'\n" << dflush_;
)";

    out << 
"}\n";

}   // lop3
