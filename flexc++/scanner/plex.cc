#include "scanner.ih"

int Scanner::pLex()
{
    int ret = lex();

    if (not Options::instance().caseSensitive())
        setMatched(String::lc(matched()));

    emsg.setLineNr(lineNr());
    wmsg.setLineNr(lineNr());

    return ret;
}

