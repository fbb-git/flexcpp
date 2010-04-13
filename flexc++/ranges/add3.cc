#include "ranges.ih"

namespace
{
    string str;
}

void Ranges::add(size_t ch)
{
    str = ch;
    add(ORDERED, str);
}
