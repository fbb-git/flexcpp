#include "scanner.hh"

int Scanner::handleMulti(int token)
{
    if (d_inBlock || d_inCharClass || d_acceptMulti)
        return token;

    accept(1);
    return Parser::CHAR;
}
