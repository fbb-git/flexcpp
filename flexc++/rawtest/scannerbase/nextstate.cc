#include "scannerbase.ih"

void ScannerBase::nextState()
{
    msg(3) << "Next state: " << d_nextState << '\n';
    d_state = d_nextState;
}
