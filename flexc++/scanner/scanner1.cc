#include "scanner.ih"

Scanner::Scanner(string const &fname)
:
    ScannerBase(fname),
    d_initialClosingBracket(false)
{
    string tag = fname + ", line";
    emsg.setLineTag(tag);
    wmsg.setLineTag(tag);
}
