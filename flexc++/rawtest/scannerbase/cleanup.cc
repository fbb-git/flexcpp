#include "scannerbase.ih"

void ScannerBase::cleanup()
{
    d_match.clear();
    d_state = 0;
    d_bol = true;
}
