#include "scanner.ih"

bool Scanner::secondSectionDelimiter()
{
    accept(0);
    return not insertedCatchAll();  // no catch all rule inserted, so a plain 
                                    // second %% section delimiter was
                                    // encountered: end input processing.
}
