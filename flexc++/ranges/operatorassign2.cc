#include "ranges.ih"

Ranges &Ranges::operator=(Ranges const &&r_tmp)
{
    Ranges tmp(std::move(r_tmp));
    swap(tmp);
    return *this;
}
