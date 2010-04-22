#include "scannerbase.ih"

void ScannerBase::atEndOfRule()
{
cerr << "atEndOfRule\n";
    d_ruleIndex = selectRule();

    if (d_ruleIndex == -1)                          // not @EOR if -1
        return;

    d_LAlength = d_accept[d_ruleIndex].length;    // pick up the LA length

    msg(2) << "     LA length = " << d_LAlength << '\n';

        // Since we're calling execute() next, make sure that the LA info is
        // saved. Later on (nextState) we determine what to do next.
        // 
    if (d_LAlength != -1)
        saveLookahead();
    
    msg(2) << "FINAL state " << d_state << " for rule " << 
                                                    d_ruleIndex  << '\n';
}

