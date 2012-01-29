#include "scanner.ih"

int Scanner::inspectBlock()
{
    redo(1);

    if (d_inBlock)
        return ' ';

    d_inBlock = true;
    return Parser::BLOCK;
}
