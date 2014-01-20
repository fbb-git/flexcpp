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
    push(d_matched.substr(tail, string::npos));
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
                                            
    begin(SC(d_startCondition + 1));        // switch to the head-matching
                                            // SC
}

inline void )" << d_baseclassScope << 
                    R"(lop3__()                // catch-all handler
{
    d_lopIter = --d_lopTail;                // increase the tail, try again
}
    
void )" << d_baseclassScope << R"(lop4__()
{
    begin(SC(d_lopSC));                     // restore original SC
    d_get = &)" << d_baseclassScope << 
                    R"(getInput;              // restore get function

    d_input.setPending(d_lopPending);

                                            // reinsert the tail into the 
                                            // input stream
    push(d_lopMatched.substr(length(), string::npos));
}

size_t )" << d_baseclassScope << R"(getLOP()
{
    return d_lopIter == d_lopEnd ? 
                static_cast<size_t>(AT_EOF) 
            : 
                *d_lopIter++;
}
)";     
// >>>> R"( section ends <<<<


}
