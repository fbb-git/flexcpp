#include "scannerbase.ih"

bool ScannerBase::callExecute()
{

//cerr << "Current rule: " << ruleIndex() << ", previous rule " << 
//d_lastRule << ", rejected flag: " << d_rejected << '\n';        
        // rejectReturn must be first to clear d_rejected if set.
    bool call = atEndOfRule() && 
                    (rejectReturn() || interactiveReturn() || noTransition());

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
