#include "block.ih"

bool Block::close()
{
    size_t lastUsedPos = d_str.find_last_not_of(' ');

    if (lastUsedPos + 4 <= d_str.length())
        d_str.resize(d_str.length() - 4);

    if (--d_level != 0)
        d_str += '}';

    return d_level;
}
