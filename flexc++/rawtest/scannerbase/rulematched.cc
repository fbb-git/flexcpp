#include "scannerbase.ih"

bool ScannerBase::ruleMatched()
{
    d_ruleIndex = selectRule();

    if (d_ruleIndex == -1)
        return false;

    saveLookahead();
    
    msg(2) << "FINAL state " << d_state << " for rule " << 
                                                    d_ruleIndex  << '\n';
    return true;
}

