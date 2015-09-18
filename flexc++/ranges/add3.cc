#include "ranges.hh"

namespace
{
    string str;
}

void Ranges::add(size_t ch)
{
    str = ch;
    add(str);
}
