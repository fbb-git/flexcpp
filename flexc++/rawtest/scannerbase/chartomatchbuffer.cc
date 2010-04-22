#include "scannerbase.ih"

void ScannerBase::charToMatchBuffer()
{
    if (plainChar())
        d_match += d_char;
}
