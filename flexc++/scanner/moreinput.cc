#include "scanner.ih"

bool Scanner::moreInput()
{
    if (popStream())            // first unwind any stacked files
        return true;

    d_endOfInput = true;

    return insertedCatchAll();
}
