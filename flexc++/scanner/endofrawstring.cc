#include "scanner.ih"

bool Scanner::endOfRawString()
{
    if (matched().rfind(d_rawString) == length() - d_rawString.length())
    {
cerr << "End of raw string " << matched() << '\n';
        d_rawString = matched().substr(0, length() - 2);
cerr << "                  " << d_rawString << '\n';
        return true;
    }

    more();
    return false;
}
