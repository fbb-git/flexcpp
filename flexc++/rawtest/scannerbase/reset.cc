#include "scannerbase.ih"

void ScannerBase::reset()
{
    d_nextState = 0;

    cerr << "Resetting to state 0\n";

    for (size_t idx = s_acceptSize; idx--; )
        d_accept[idx] = 0;
}
