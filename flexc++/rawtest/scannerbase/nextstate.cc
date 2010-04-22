#include "scannerbase.ih"

void ScannerBase::nextState()
{
        // transitions (T) at EOR or not at EOR (R) are handled identically.
        // T, R, CHR adds the char, T, R, CHR|BOL|EOF are performed.
        // at EOF the next state is a no-transition on EOF and there the 
        // EOF condition is handled.
        // 
    if (transition())
    {
        d_fromState = d_state;
        d_state = d_nextState;
        return;
    }

    // No transitions
    //
    // this means that we don't know how to proceed. Plain characters generate 
    // error output to cerr and the DFA is reset; BOLs are ignored and
    // processing continues at the current state, EOFs are handled by either
    // popping the next stream, keeping the state and continuing or by
    // throwing -1 and thus ending lex with the EOF token. In rawtest file
    // switching hasn't been implemented.

    if (plainChar())
    {
        input();                            // remove unknown char from
                                            // the queue, pushed by callExec.
        cerr << "NOT HANDLED: '" << d_char << "'\n";   // ECHO it to cerr
        reset();
        return;
    }

    if (atBOL())
        return;
        
    // else EOF

    msg(1) << "Got EOF, all done\n";
    throw -1;                       // for now we'll end the scanner
}
