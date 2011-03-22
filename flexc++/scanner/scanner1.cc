#include "scanner.ih"

Scanner::Scanner(string const &fname)
:
    ScannerBase(new StreamInfoType(fname)),
    d_filename(fname),
    d_initialClosingBracket(false)
{
    string tag = fname + ", line";
    emsg.setLineTag(tag);
    wmsg.setLineTag(tag);
}
