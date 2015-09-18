#include "parser.hh"

Pattern Parser::eolnDollar()
{
    d_scanner.eolnDollar();
    return rawText("");
}
