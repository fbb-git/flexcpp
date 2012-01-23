#include "parser.ih"

spSemUnion Parser::head()
{
    d_scanner.accept(1);                // accept the 1st char

    return rawText();
}


