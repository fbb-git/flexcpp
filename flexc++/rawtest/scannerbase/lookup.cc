#include "scannerbase.ih"

bool ScannerBase::lookup(size_t range)
{
    size_t nextState = d_dfa[d_state][range];   // determine the next state

    if (nextState != 0)                 // got a transition
    {
        d_state = nextState;
        return true;
    }

    if (range == s_rangeOfEOF)          // at EOF switch files if possible
        throw -1;                       // for now we'll end the scanner

    if (range == s_rangeOfBOL)          // at BOL, nothing happens: false
        return false;                   // get the next char.

        // now we're in trouble: an unaccounted-for range...
    cerr << d_char;                     // ECHO it to cerr
    cleanup();
    return false;                       // get the next char
}
            

        
