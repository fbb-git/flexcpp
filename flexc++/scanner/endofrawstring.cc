#include "scanner.hh"

bool Scanner::endOfRawString()
{
    if (matched().rfind(d_rawString) == length() - d_rawString.length())
        return true;

    more();
    return false;
}
