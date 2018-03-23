#include "scanner.ih"

int Scanner::handleOpenBracket()
{
    if (startCondition() == StartCondition_::INITIAL)
    {
        if (d_inCharClass)
            return '[';

        d_inCharClass = true;
    }
    return Parser::CC_START;
}

