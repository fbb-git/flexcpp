#include "block.ih"

bool Block::close()
{
    return --d_level == 0;
}
