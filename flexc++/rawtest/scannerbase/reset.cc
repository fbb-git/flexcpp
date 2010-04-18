#include "scannerbase.ih"

void ScannerBase::reset()
{
    d_state = d_nextState;

    for (size_t idx = s_acceptSize; idx--; )
        d_accept[idx] = 0;
}
