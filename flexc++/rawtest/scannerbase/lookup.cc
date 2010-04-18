#include "scannerbase.ih"

bool ScannerBase::lookup(size_t range)
{
    // Char-ranges are numbers, to convert to indices subtract 1

    cerr << "State: " << d_state << ": lookup(" << range;
    d_nextState = d_dfa[d_state][range - 1];// determine the next state
    cerr << ") yields next state " << d_nextState << '\n';

    if 
    (
        d_nextState != 0                // got a transition
        ||
        finalState()                    // or a final state
    )
        return true;                    // then lookup continues.


    if (range == s_rangeOfEOF)          // at EOF switch files if possible
    {
        cerr << "Got EOF, all done\n";
        throw -1;                       // for now we'll end the scanner
    }

    if (range == s_rangeOfBOL)          // at BOL, nothing happens: false
        return false;                   // get the next char.

        // now we're in trouble: an unaccounted-for range...
    cerr << "NOT HANDLED: '" << d_char << "'\n";   // ECHO it to cerr
    cleanup();
    return false;                       // get the next char
}
            

        
