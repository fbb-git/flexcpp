#include "scannerbase.ih"

bool ScannerBase::callExecute()
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
    {
        string const &tail = d_match.substr(d_length);

        copy(tail.rbegin(), tail.rend(), 
                    front_inserter(d_deque));
        d_match.resize(d_length);

        msg(1) << "Calling execute with match = '" << d_match << "'\n";
    }
    else
        msg(2) << "Not calling execute\n";

    return ret;
}
