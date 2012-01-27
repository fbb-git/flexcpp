#include "parser.ih"

spSemUnion Parser::head()
{
    d_scanner.accept(1);                // accept the 1st char, redo the rest
    return rawText();                   // see inc/regex for details
}


