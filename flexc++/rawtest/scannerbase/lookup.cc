#include "scannerbase.ih"

// Three variables play a role here:
//     1. The nextstate: if 0 then there is no transition
//     2. The current state: either a final state or a non-final state
//     3. the character ranges: BOL, EOF or character-range

void ScannerBase::lookup()
{
    next();

    msg(1) << "DFA[" << d_state << "][" << d_range << "] = ";

    d_nextState = d_dfa[d_state][d_range];    // determine the next state

    if (d_state == d_rejectFrom && d_nextState == d_rejectTo)
        d_nextState = -1;

    msg(1) << "nextState = " << d_nextState << " (char = ";
    if (d_range == s_rangeOfBOL)
        msg(1) << "BOL)\n";
    else if (d_range == s_rangeOfEOF)
        msg(1) << "EOF)\n";
    else if (isprint(d_char))
        msg(1) << '\'' << d_char << "')\n";
    else
        msg(1) << 
            static_cast<size_t>(static_cast<unsigned char>(d_char)) <<
            ")\n";
}
            

        
