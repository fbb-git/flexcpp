#include "scanner.ih"

int Scanner::pLex()
{
    int ret = lex();

    emsg.setLineNr(lineno());
    wmsg.setLineNr(lineno());

    d_beginOfPattern = false;
    return ret;
}

