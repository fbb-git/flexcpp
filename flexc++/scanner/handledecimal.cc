#include "scanner.ih"

int Scanner::handleDecimal()
{
    if (d_inBlock || d_inCharClass || d_acceptIdentifier)
        return Parser::DECIMAL;

    accept(1);
    return Parser::CHAR;
}
