#include "dfarow.ih"

void DFARow::uniqueMap(vector<size_t> const &xlat)
{
    for (auto &transition: d_map)
        translate(transition, xlat);
}

