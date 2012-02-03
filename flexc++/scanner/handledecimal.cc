#include "scanner.ih"

int Scanner::handleDecimal()
{
    if (d_inCharClass)
        return Parser::DECIMAL;

    accept(1);
    return Parser::CHAR;
}
