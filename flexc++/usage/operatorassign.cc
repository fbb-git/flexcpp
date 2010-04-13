#include "usage.ih"

Usage &Usage::operator=(Usage const &other)
{
    Usage tmp(other);
    swap(tmp);
    return *this;
}
