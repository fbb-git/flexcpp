#include "scannerbase.ih"

bool ScannerBase::finalState()
{
    int ruleIdx = d_dfa[d_state][s_finalIdx];

    bool ret = ruleIdx != -1;
    if (!ret) 
        d_lookaheadLength = 0;
    else
    {
        d_lookaheadLength = d_accept[ruleIdx];
        msg(1) << "FINAL state " << d_state << 
                " for rule " << ruleIdx << ". Matched: " << 
                  d_match << ", accept count = " << d_lookaheadLength << '\n';
    }        

    return ret;
}

