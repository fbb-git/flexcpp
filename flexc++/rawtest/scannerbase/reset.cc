#include "scannerbase.ih"

void ScannerBase::reset()
{
    d_length = 0;
    d_state = 0;
    d_lookaheadLength = 0;

    d_match.clear();

    msg(1) << "Resetting...\n";

    for (size_t idx = s_acceptSize; idx--; )
        d_accept[idx] = 0;
}
