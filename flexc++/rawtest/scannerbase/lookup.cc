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

    msg(1) << "nextState = " << d_nextState << "\n";
}
            

        
