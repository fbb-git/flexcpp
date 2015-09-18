#include "scannerbase.hh"

ScannerBase::ScannerBase()
:
    d_dfa(s_dfa),           // declared in DECLARE; initialize to INITIAL
    d_bol(s_rangeOfBOL),
        // d_char
        // d_state          // by reset()
        // d_nextState
        // d_range
    d_more(false)
{
    reset();
}
