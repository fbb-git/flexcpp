#include "scannerbase.ih"

void ScannerBase::cleanup()
{
    d_match.clear();
    d_nextState = 0;
}
