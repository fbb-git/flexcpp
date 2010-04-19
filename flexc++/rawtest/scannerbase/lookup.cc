#include "scannerbase.ih"

bool ScannerBase::lookup(size_t range)
{
    // Char-ranges are numbers, to convert to indices subtract 1

    msg(2) << "State: " << d_state << ": lookup(" << range;
    d_nextState = d_dfa[d_state][range - 1];// determine the next state
    msg(2) << ") yields next state " << d_nextState << '\n';

    if (d_nextState != 0)               // got a transition
        return true;

    if (range == s_rangeOfEOF)          // at EOF switch files if possible
    {
        msg(1) << "Got EOF, all done\n";
        throw -1;                       // for now we'll end the scanner
    }

    if (range == s_rangeOfBOL)          // at BOL, nothing happens: false
        return false;                   // get the next char.

    if (finalState())                   // or a final state
    {
        d_deque.push_front(d_char);     // re-read the last-read char
        return true;                    // then lookup continues.
    }

        // now we're in trouble: an unaccounted-for range...
    cerr << "NOT HANDLED: '" << d_char << "'\n";   // ECHO it to cerr
    cleanup();
    return false;                       // get the next char
}
            

        
