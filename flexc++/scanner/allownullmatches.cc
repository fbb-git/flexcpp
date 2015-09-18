#include "scanner.hh"

bool Scanner::allowNullMatches()
{
    bool ret = d_allowNullMatches;
    d_allowNullMatches = false;
    return ret;
}

