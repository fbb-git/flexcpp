#include "scanner.ih"

bool Scanner::allowNullMatches()
{
    bool ret = d_allowNullMatches;
    d_allowNullMatches = false;
    return ret;
}

