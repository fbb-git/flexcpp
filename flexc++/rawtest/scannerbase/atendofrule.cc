#include "scannerbase.ih"

bool ScannerBase::atEndOfRule()
{
    int rule = ruleIndex();                         // what rule?

    if (rule == -1)                                 // not @EOR if -1
        return false;

    d_lookaheadLength = d_accept[rule];             // pick up the LA length

        // Since we're calling execute() next, make sure that the LA info is
        // saved. Later on (nextState) we determine what to do next.
        // 
    if (d_lookaheadLength != 0)
        saveLookahead();
    
    msg(1) << "FINAL state " << d_state << 
            " for rule " << rule << ". Matched: " << 
              d_match << ", accept count = " << d_lookaheadLength << '\n';

    return true;
}

