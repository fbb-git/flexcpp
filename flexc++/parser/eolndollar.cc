#include "parser.ih"

spSemUnion Parser::eolnDollar()
{
    d_scanner.eolnDollar();
    return rawText("");
}
