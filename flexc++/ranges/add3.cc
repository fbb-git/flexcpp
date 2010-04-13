#include "usage.ih"

namespace
{
    string str;
}

void Usage::add(size_t ch)
{
    str = ch;
    add(ORDERED, str);
}
