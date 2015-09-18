#include "scannerbase.hh"

void ScannerBase::notHandledChar() const
{
    cerr << "NOT HANDLED: '" << d_char << "'\n";   // ECHO it to cerr
}
