#include "scannerbase.ih"

void ScannerBase::reset()
{
    d_state = 0;
    d_match.clear();

    msg(3) << "Reset to state 0\n";

    for (size_t idx = s_acceptSize; idx--; )
        d_accept[idx] = 0;
}
