#include "scannerbase.ih"

void ScannerBase::nextState()
{
    if (d_nextState != -1)              // got a transition
    {
        if (d_range < s_rangeOfEOF)
            d_match += d_char;

        d_state = d_nextState;
        return;
    }


        // No transition on `range' from d_state

    if (d_range == s_rangeOfEOF)      // at EOF switch files if possible
    {
        // try to pop a stream and continue (return false), or:
        msg(1) << "Got EOF, all done\n";
        throw -1;                       // for now we'll end the scanner
    }


    if (d_range == s_rangeOfBOL)        // at BOL keep d_state and try again
    {                                   // with the next char
        msg(3) << "no BOL transition: maintaining state " << d_state << "\n";
        return;                         // get the next char.
    }

    // At this point we've seen a character, but no transition from it.

    if (finalState())                   // no continuation at FINAL state
    {
        msg(3) << "No transition at FINAL: pushing back " << d_char << '\n';
        d_deque.push_front(d_char);     // re-read the last-read char
    }
    else    // now we're in trouble: an unaccounted-for range...
    {
        cerr << "NOT HANDLED: '" << d_char << "'\n";   // ECHO it to cerr
        d_match.clear();
    }

    d_state = 0;
}
