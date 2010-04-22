#include "scannerbase.ih"

bool ScannerBase::endOfRule()
{
    d_ruleIndex = selectRule();

    return d_ruleIndex != -1;


//    d_LAsize = d_accept[d_ruleIndex].LAsize;    // pick up the LA length
//
//    msg(2) << "     LA length = " << d_LAsize << '\n';
//
//        // Since we're calling execute() next, make sure that the LA info is
//        // saved. Later on (nextState) we determine what to do next.
//        // 
//    if (d_LAsize != -1)
//        saveLookahead();
//    
//    msg(2) << "FINAL state " << d_state << " for rule " << 
//                                                    d_ruleIndex  << '\n';
}

