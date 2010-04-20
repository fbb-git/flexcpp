#include "scannerbase.ih"

void ScannerBase::reset()
{
    d_state = 0;

    if (d_more)
        d_more = false;
    else
        d_match.clear();

    msg(1) << "\nResetting...\n";

    for (size_t idx = s_acceptSize; idx--; )
        d_accept[idx] = 0;
}
