#include "scannerbase.ih"

bool ScannerBase::finalState()
{
    int ruleIdx = d_dfa[d_state][s_finalIdx];

    bool ret = ruleIdx != -1;
    if (ret) 
    {
        d_length = d_accept[ruleIdx];
        msg(1) << "FINAL state of rule " << ruleIdx << ". Matched: " << 
                  d_match << ", accept count = " << d_length << '\n';
        if (d_length == 0)
            d_length = d_match.length();
    }        

    return ret;
}

