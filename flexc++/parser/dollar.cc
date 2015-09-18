#include "parser.hh"

Pattern Parser::dollar()
{
    if (not d_warnDollars)
        wmsg << "`$' inside regex loses its special meaning" << endl;
    d_warnDollars = true;

    return rawText("$");
}
