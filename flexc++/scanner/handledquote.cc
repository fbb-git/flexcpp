#include "scanner.ih"

bool Scanner::handleDquote()
{
    if (d_inCharClass)
        return true;

    more();
    push(StartCondition__::string);
    return false;
}
