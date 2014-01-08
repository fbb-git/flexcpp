#include "ranges.ih"

Ranges::~Ranges()
{
    delete[] d_alphabet;
    delete[] d_used;
}
