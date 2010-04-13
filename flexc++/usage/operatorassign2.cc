#include "usage.ih"

Usage &Usage::operator=(Usage const &&r_tmp)
{
    Usage tmp(std::move(r_tmp));
    swap(tmp);
    return *this;
}
