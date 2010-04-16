#include "ranges.ih"

#include <iostream>

void Ranges::subsetCount()
{
    d_subsets = 1;
    for 
    (
        auto iter = d_ranges + 1, end = d_ranges + d_size; 
            iter != end;
                ++iter
    )
    {
        if (*(iter - 1) != *iter)
            ++d_subsets;
    }
}
