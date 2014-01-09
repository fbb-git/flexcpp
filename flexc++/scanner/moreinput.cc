#include "scanner.ih"

bool Scanner::moreInput()
{
    if (popStream())            // first unwind any stacked files
        return true;

    if (d_catchAll.length())    // if any input waiting on d_catchall
    {                           // then process it now.
        push(d_catchAll);
        d_catchAll.clear();
        return true;
    }

    return false;               // no more input.
}
