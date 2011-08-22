#include "ranges.ih"

Ranges &Ranges::operator=(Ranges &&r_tmp)
{
    Ranges tmp(std::move(r_tmp));
    swap(tmp);
    return *this;
}
