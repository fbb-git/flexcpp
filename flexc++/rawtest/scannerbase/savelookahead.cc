#include "scannerbase.ih"

void ScannerBase::saveLookahead()
{
    retain(d_LAsize);

    d_bol = false;                      // prevent BOL from being returned
}
