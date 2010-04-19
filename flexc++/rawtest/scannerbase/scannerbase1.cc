#include "scannerbase.ih"

ScannerBase::ScannerBase()
:
    d_dfa(s_dfa),   // declared in DECLARE; initialize to INITIAL
    d_bol(s_rangeOfBOL),
    d_more(false)
{
}
