#include "block.ih"

bool Block::close()
{
    if (--d_level != 0)
        *this += '}';

    return d_level;
}
