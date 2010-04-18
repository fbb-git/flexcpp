#include "scannerbase.ih"

void ScannerBase::nextState()
{
    cerr << "Next state: " << d_nextState << '\n';
    d_state = d_nextState;
}
