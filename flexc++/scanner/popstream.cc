#include "scanner.hh"

bool Scanner::popStream()
{
    if (not ScannerBase::popStream())
        return false;

    setLineTags(filename());
    return true;
}
