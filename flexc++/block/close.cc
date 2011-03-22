#include "block.ih"

bool Block::close()
{
    if (--d_level != 0)
        d_block += '}';

    return d_level;
}
