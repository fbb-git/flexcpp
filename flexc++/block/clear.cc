#include "block.ih"

void Block::clear()
{
    d_block.erase();
    d_level = 0;
}
