#include "scanner.ih"

Scanner::Scanner(string const &fname)
:
    ScannerBase(fname, "-")
{
    setLineTags(fname);
    push(StartCondition__::pre);
}


