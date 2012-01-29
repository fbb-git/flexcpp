#include "scanner.ih"

int Scanner::pLex()
{
    int ret = lex();

    emsg.setLineNr(lineNr());
    wmsg.setLineNr(lineNr());

    return ret;
}

