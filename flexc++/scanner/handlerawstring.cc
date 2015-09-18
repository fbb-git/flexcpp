#include "scanner.hh"

bool Scanner::handleRawString()
{
    if (d_inCharClass)
    {
        accept(1);
        return false;
    };

    d_rawString = matched();
    d_rawString.erase(0, 1);        // rm the R

    d_rawString.front() = ')';      // end sentinel is )IDENTIFIER"
    d_rawString.back() = '"';

    more();
    push(StartCondition__::rawstring);
    return true;
}
