#include "scannerbase.ih"

ScannerBase::ScannerBase()
:
    d_bol(true),
    d_state(0),
    d_dfa(s_dfa)    // initialize to INITIAL
{
}
