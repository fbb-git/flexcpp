#include "dfarow.ih"

void DFARow::uniqueMap(vector<size_t> const &xlat)
{
    for_each(
        d_map.begin(), d_map.end(), 
        [&](MapValue &transition)
        {
            translate(transition, xlat);
        }
    );
}

