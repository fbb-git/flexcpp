#include "scanner.ih"

void Scanner::switchToINITIAL()
{
    d_scStack = SCStack();
    begin(StartCondition__::INITIAL);
}
