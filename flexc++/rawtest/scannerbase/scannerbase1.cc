#include "scannerbase.ih"

ScannerBase::ScannerBase()
:
    d_bol(s_rangeOfBOL),
    d_nextState(0),
    d_dfa(s_dfa)    // initialize to INITIAL
{
}
