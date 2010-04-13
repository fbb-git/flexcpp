#include "block.ih"

bool Block::operator()(int ch)
{
    if (d_level == 0)
        return false;

    *this += ch;
    return true;
}
