#include "scanner.ih"

int Scanner::pLex()
{
    int ret = lex();

    if (not d_caseSensitive)
        setMatched(String::lc(matched()));

    emsg.setLineNr(lineNr());
    wmsg.setLineNr(lineNr());

    return ret;
}

