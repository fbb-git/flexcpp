#include "scanner.ih"

int Scanner::pLex()
{
    int ret = lex();

    emsg.setLineNr(lineNr());
    wmsg.setLineNr(lineNr());

//    d_beginOfPattern = false;
    return ret;
}

