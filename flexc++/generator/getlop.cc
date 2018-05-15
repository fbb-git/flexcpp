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
    if (s_debug_)
    {
        s_out_ << "getLOP() returns ";
        if (isprint(ch))
            s_out_ << '`' << as<char>(ch) << '\'';
        else
            s_out_ << "(int)" << as<int>(ch);
        s_out_ << '\n' << dflush_;
    }
)raw";

    out << R"(
    return ch;
}
)";     

} // getLOP
