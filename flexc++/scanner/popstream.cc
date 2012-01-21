#include "scanner.ih"

bool Scanner::popStream()
{
    if (not ScannerBase::popStream())
        return false;

    setLineTags(filename());
    return true;
}
