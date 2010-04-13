#include "ranges.ih"

Ranges &Ranges::operator=(Ranges const &other)
{
    Ranges tmp(other);
    swap(tmp);
    return *this;
}
