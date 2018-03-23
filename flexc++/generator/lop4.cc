#include "generator.ih"

void Generator::lop4(ostream &out) const
{
    out <<    
"void " << d_baseclassScope << R"(lop4_()
{
)";

    if (d_debug)
        out << 
R"(
    if (s_debug_)
        s_out_ << "lop4_ matched head `" << d_matched << "'\n"
                "       re-scan `" << 
                d_lopMatched.substr(length(), std::string::npos) << "'\n" << 
                dflush_;
)";

        out << 
R"(
    begin(SC(d_lopSC));                     // restore original SC
    d_get = &)" << d_baseclassScope << 
                            R"(getInput;          // restore get function

    d_input.setPending(d_lopPending);
                                            // reinsert the tail into the 
                                            // input stream
    push(d_lopMatched.substr(length(), std::string::npos));
}
)";

} // lop4
