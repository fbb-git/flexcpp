#include "parser.ih"

Pattern Parser::eolnDollar()
{
    d_scanner.eolnDollar();
    return rawText("");
}
