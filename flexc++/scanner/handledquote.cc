#include "scanner.hh"

bool Scanner::handleDquote()
{
    if (d_inCharClass)
        return true;

    more();
    push(StartCondition__::string);
    return false;
}
