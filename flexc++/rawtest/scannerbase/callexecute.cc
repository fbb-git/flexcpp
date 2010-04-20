#include "scannerbase.ih"

bool ScannerBase::callExecute()
{
    d_length = d_match.length();

    bool call = atEndOfRule() && (interactiveReturn() || noTransition());

    if (!call)
        msg(2) << "Not calling execute\n";
    else
    {
        d_deque.push_front(d_char);     // reread the non-continuing char.
                                        // after a reset.
        msg(1) << "Calling execute. Matched: '" << d_match << "'\n";
    }

    return call;
}
