#include "parser.ih"

spSemUnion Parser::dollar()
{
    if (not d_warnDollars)
        wmsg << "`$' inside regex loses its special meaning" << endl;
    d_warnDollars = true;

    spSemUnion ret(rawText("$"));

    return ret;
}
