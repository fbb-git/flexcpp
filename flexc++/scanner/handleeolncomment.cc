#include "scanner.ih"

bool Scanner::handleEOLNcomment()
{
    if (not d_inCharClass)
    {
        if (matched() == "//%nowarn")
            d_allowNullMatches = true;
        return false;
    }

    accept(matched().find("//") + 2);   // in char class: accept blanks + //
    return true;                        // and rescan the rest
}
