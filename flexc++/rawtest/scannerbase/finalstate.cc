#include "scannerbase.ih"

bool ScannerBase::finalState() const
{
    int ruleIdx = d_dfa[d_state][s_finalIdx];
    bool ret = ruleIdx != -1;
    if (ret) 
        cerr << "Reached FINAL state of rule " << ruleIdx << '\n';
    return ret;
}

