#include "block.ih"

bool Block::operator()(string const &text)
{
    if (d_level == 0)
        return false;

    *this += text;
    return true;
}
