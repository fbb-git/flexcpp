#include "scanner.ih"

int Scanner::begin(StartCondition__ to, int token)
{
    begin(to);
    return token;
}

