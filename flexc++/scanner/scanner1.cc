#include "scanner.ih"

Scanner::Scanner(string const &fname)
:
    ScannerBase(fname, "-"),
    d_inBlock(false),
    d_inCharClass(false)
{
    setLineTags(fname);
    push(StartCondition__::pre);
}


