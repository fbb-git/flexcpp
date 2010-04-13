#include "scanner.ih"

int Scanner::pLex()
{
    int ret = lex();
    d_beginOfPattern = false;
    return ret;
}

