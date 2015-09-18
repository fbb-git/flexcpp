#include "scanner.hh"

Scanner::Scanner(std::istream &in, std::ostream &out)
:
    ScannerBase(in, out)
{
    push(StartCondition__::pre);
}

