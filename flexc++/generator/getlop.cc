#include "generator.ih"

void Generator::getLOP(ostream &out) const 
{
    out <<    
"size_t " << d_baseclassScope << R"(getLOP()
{
    size_t ch = d_lopIter == d_lopEnd ? as<size_t>(AT_EOF) : *d_lopIter++;
)";
    
    if (d_debug)
        out << 
R"raw(
    if (s_debug__)
    {
        s_out__ << "getLOP() returns ";
        if (isprint(ch))
            s_out__ << '`' << as<char>(ch) << '\'';
        else
            s_out__ << "(int)" << as<int>(ch);
        s_out__ << '\n' << dflush__;
    }
)raw";

    out << R"(
    return ch;
}
)";     

} // getLOP
