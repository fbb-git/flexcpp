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

    if (!ret)
        msg(2) << "Not calling execute\n";
    else
    {
        if (d_lookaheadLength)
        {
            d_length = 0;

            d_deque.push_front(d_char);

            size_t beginTail = d_length + d_lookaheadLength;
            string const &tail = d_match.substr(beginTail);

            copy(tail.rbegin(), tail.rend(), front_inserter(d_deque));
            d_match.resize(beginTail);
        }
        msg(1) << "Calling execute with match = '" << d_match << "'\n";
    }

    return ret;
}
