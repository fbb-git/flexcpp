#include "scannerbase.ih"

bool ScannerBase::ruleMatched()
{
    d_ruleIndex = selectRule();

    if (d_ruleIndex == -1)
        return false;

    d_LAsize = d_accept[d_ruleIndex].LAsize;    // pick up the LA length

    msg(2) << "     LA length = " << d_LAsize << '\n';

    if (d_LAsize != -1)
        saveLookahead();
    
    msg(2) << "FINAL state " << d_state << " for rule " << 
                                                    d_ruleIndex  << '\n';
    return true;
}

