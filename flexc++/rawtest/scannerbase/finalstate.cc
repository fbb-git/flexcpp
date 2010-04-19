#include "scannerbase.ih"

bool ScannerBase::finalState() const
{
    int ruleIdx = d_dfa[d_state][s_finalIdx];

    bool ret = ruleIdx != -1;
    if (ret) 
        msg(3) << "FINAL state of rule " << ruleIdx << ". Matched: " << 
                    d_match << '\n';

    return ret;
}

