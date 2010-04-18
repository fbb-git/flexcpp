#include "scannerbase.ih"

bool ScannerBase::confirmExecute() const
{
    return 
        finalState()            // at a FINAL state
        &&
        (                       // if a newline in an interactive scanner
            (s_interactive && d_char == '\n')
            ||
            d_nextState == 0    // or there are no known transitions
        );
}
