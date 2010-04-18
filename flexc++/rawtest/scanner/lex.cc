#include "scanner.ih"


int Scanner::lex()
try
{
    while (true)
    {
        if (!lookup(next()))
            continue;
    }
}
catch (int ret)
{
    return ret;
}

