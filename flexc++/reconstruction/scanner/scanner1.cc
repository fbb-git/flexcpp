#include "scanner.ih"

Scanner::Scanner(std::istream &in, std::ostream &out)
:
    ScannerBase(in, out)
{
    push(StartCondition__::pre);
}

