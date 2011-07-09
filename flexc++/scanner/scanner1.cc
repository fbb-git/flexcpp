#include "scanner.ih"

Scanner::Scanner(string const &fname)
:
    ScannerBase(fname, "-"),
    d_initialClosingBracket(false)
{
    setLineTags(fname);
}
