#include "scanner.hh"

int Scanner::handleOpenBracket()
{
    if (startCondition() == StartCondition__::INITIAL)
    {
        if (d_inCharClass)
            return '[';

        d_inCharClass = true;
    }
    return Parser::CC_START;
}

