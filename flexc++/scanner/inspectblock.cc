#include "scanner.ih"

int Scanner::inspectBlock()
{
    redo(1);

    if (d_inBlock || d_inCharClass)
        return ' ';

    d_inBlock = true;
    return Parser::BLOCK;
}
