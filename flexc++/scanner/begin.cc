#include "scanner.ih"

int Scanner::begin(StartCondition to, int token)
{
    begin(to);
    return token;
}

