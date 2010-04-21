#include "scannerbase.ih"

bool ScannerBase::atEndOfRule()
{
    int rule = ruleIndex();                         // what rule?

    if (rule == -1)                                 // not @EOR if -1
        return false;

    d_LAlength = d_accept[rule].length;             // pick up the LA length

    msg(1) << "At EOR " << rule << ", LA prefix = " << d_LAlength << '\n';

        // Since we're calling execute() next, make sure that the LA info is
        // saved. Later on (nextState) we determine what to do next.
        // 
    if (d_LAlength != 0)
        saveLookahead();
    
    msg(1) << "FINAL state " << d_state << 
            " for rule " << rule << ". Matched: " << d_match << '\n';

    return true;
}

