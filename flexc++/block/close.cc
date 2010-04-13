#include "block.ih"

bool Block::close()
{
    *this += "}";
    return --d_level == 0;
}
