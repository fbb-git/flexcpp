#include "ranges.hh"

Ranges &Ranges::operator=(Ranges const &other)
{
    Ranges tmp(other);
    swap(tmp);
    return *this;
}
