#include "scanner.hh"

void Scanner::switchToINITIAL()
{
    d_scStack = SCStack();
    begin(StartCondition__::INITIAL);
}
