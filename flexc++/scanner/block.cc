#include "scanner.ih"

int Scanner::block()
{
    accept(matched().find_first_not_of(" \t")); // remove initial blanks
    d_inBlock = true;
    return Parser::BLOCK;
}
