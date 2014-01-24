#include "generator.ih"

void Generator::lopImplementation(std::ostream &out) const
{
    if (not d_lopUsed)
        return;

    key(out);


    if (d_rules.hasFixedTailLOPrules())
        out << 
"void " << d_baseclassScope << R"(lopf__(size_t tail)
{
    tail = length() - tail;
    push(d_matched.substr(tail, std::string::npos));
    d_matched.resize(tail);
}

)";     
// >>>> R"( section ends <<<<


    if (d_rules.hasVariableTailLOPrules())
        out <<
"void " << d_baseclassScope << R"(lop1__(int lopSC)
{
    d_lopMatched = d_matched;
    d_lopPending = d_input.nPending();

    d_lopEnd = d_lopMatched.end();
    d_lopTail = d_lopEnd - 1;
    d_lopIter = d_lopTail;

)";
// >>>> R"( section ends <<<<

    if (d_debug)
        out << 
        R"(    s_out__ << "lop1__ received `" << )"
                                R"(d_lopMatched << "\'\n" << dflush__;
        )";

        out << R"(
    d_get = &)" << d_baseclassScope << R"(getLOP;

    d_lopSC = d_startCondition;             // remember original SC
    begin(SC(lopSC));                       // activate the 
                                            // tail-matching SC
}

void )" << d_baseclassScope << 
                R"(lop2__()                       // matched the tail
{
    d_lopEnd = d_lopTail;                   // read the head
    d_lopIter = d_lopMatched.begin();
)";
// >>>> R"( section ends <<<<

    if (d_debug)
        out << R"(
    s_out__ << "lop2__ matched tail `" << )"
                                        R"(d_matched << "\'\n" << dflush__;
    )";
                                            
        out << R"(
    begin(SC(d_startCondition + 1));        // switch to the head-matching
}                                           // SC

inline void )" << d_baseclassScope << 
                    R"(lop3__()                // catch-all handler
{
    d_lopIter = --d_lopTail;                // increase the tail, try again
)";
// >>>> R"( section ends <<<<

    if (d_debug)
        out <<
        R"(
    s_out__ << "lop3__: now try to match tail `" << 
               std::string(d_lopIter, d_lopEnd) << "'\n" << dflush__;
    )";

    out << R"(
}
    
void )" << d_baseclassScope << R"(lop4__()
{
)";
// >>>> R"( section ends <<<<

    if (d_debug)
        out << R"(
    s_out__ << "lop4__ matched head `" << d_matched << "'\n"
                "       re-scan `" << 
                d_lopMatched.substr(length(), std::string::npos) << "'\n" << 
                dflush__;
    )";

        out << R"(
    begin(SC(d_lopSC));                     // restore original SC
    d_get = &)" << d_baseclassScope << 
                    R"(getInput;              // restore get function

    d_input.setPending(d_lopPending);

                                            // reinsert the tail into the 
                                            // input stream
    push(d_lopMatched.substr(length(), std::string::npos));
}

size_t )" << d_baseclassScope << R"(getLOP()
{
    size_t ch = d_lopIter == d_lopEnd ? 
                as<size_t>(AT_EOF) 
            : 
                *d_lopIter++;
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
// >>>> R"( section ends <<<<

}
