#include "scannerbase.ih"

ScannerBase::ScannerBase()
:
    d_dfa(s_dfa),           // declared in DECLARE; initialize to INITIAL
    d_bol(s_rangeOfBOL),
        // d_char
        // d_state          // by reset()
        // d_nextState
        // d_range
        // d_LAlength       // by reset()
    d_more(false),
    d_rejectFrom(-2)
{
    reset();
}
