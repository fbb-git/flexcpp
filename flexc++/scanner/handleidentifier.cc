#include "scanner.ih"

int Scanner::handleIdentifier()
{
    if (d_inCharClass || d_acceptIdentifier)
        return Parser::IDENTIFIER;

    accept(1);
    return Parser::CHAR;
}
