#include "scanner.ih"

bool Scanner::insertedCatchAll()
{
    if (not d_catchAll.length())    // if no catch-all rule required
        return false;

    push(d_catchAll);
    d_catchAll.clear();
    return true;
}
