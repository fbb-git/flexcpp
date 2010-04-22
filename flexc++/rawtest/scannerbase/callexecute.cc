#include "scannerbase.ih"

bool ScannerBase::callExecute()
{
    updateAcceptCounts();
        
    atEndOfRule();

    bool call = ruleAvailable() && (interactiveReturn() || noTransition());

    if (!call)
        msg(2) << "Not calling execute\n";
    else
    {
        if (d_range < s_rangeOfEOF)
            d_deque.push_front(d_char); // reread the non-continuing char.
                                        // after a reset.
        msg(1) << "Calling execute for rule " << d_ruleIndex << 
                    ". LAsize = " << d_accept[d_ruleIndex].LAsize << 
                    ", Matched: '" << d_match << "'\n";
    }

    return call;
}
