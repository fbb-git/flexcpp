#include "scannerbase.ih"

// Three variables play a role here:
//     1. The nextstate: if 0 then there is no transition
//     2. The current state: either a final state or a non-final state
//     3. the character ranges: BOL, EOF or character-range

void ScannerBase::lookup()
{
    size_t range = next();
    // Char-ranges are numbers, to convert to indices subtract 1

    msg(1) << "DFA[" << d_state << "][" << range << "] = ";

    d_nextState = d_dfa[d_state][range];    // determine the next state

    msg(1) << "nextState = " << d_nextState << "\n";
}
            

        
