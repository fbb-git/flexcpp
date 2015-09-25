#include "block.ih"

void Block::clear()
{
    d_str.erase();
    d_level = 0;
}
