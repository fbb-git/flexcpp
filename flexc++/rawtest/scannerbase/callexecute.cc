#include "scannerbase.ih"

bool ScannerBase::callExecute() const
{
    bool ret = 
        finalState()            // at a FINAL state
        &&
        (                       // if a newline in an interactive scanner
            (s_interactive && d_char == '\n')
            ||
            d_nextState == -1   // or there is no known transition
        );

    if (ret)
        msg(4) << "Calling execute\n";
    else
        msg(4) << "Not calling execute\n";

    return ret;
}
