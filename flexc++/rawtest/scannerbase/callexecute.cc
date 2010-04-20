#include "scannerbase.ih"

bool ScannerBase::callExecute()
{
    bool call = atEndOfRule() && 
                    (interactiveReturn() || noTransition());

    if (!call)
        msg(2) << "Not calling execute\n";
    else
    {
        if (d_range < s_rangeOfEOF)
            d_deque.push_front(d_char); // reread the non-continuing char.
                                        // after a reset.
        msg(1) << "Calling execute. Matched: '" << d_match << "'\n";
    }

    return call;
}
