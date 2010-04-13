#include "scanner.ih"

Scanner::Scanner(string const &fname)
:
    ScannerBase(new StreamInfoType(fname)),
    d_initialClosingBracket(false)
{}
