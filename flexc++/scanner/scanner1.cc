#include "scanner.ih"

Scanner::Scanner(string const &fname)
:
    ScannerBase(fname, "-"),
    d_inBlock(false),
    d_inCharClass(false),
    d_acceptMulti(true),
    d_caseSensitive(true)
{
    setLineTags(fname);
    push(StartCondition_::pre);
}


