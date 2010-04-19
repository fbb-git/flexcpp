#include "ranges.ih"

void Ranges::subsetCount()
{
    d_subsets = 0;

    size_t *begin = d_ranges;
    size_t *end = d_ranges + d_size;
    while (begin != end)
    {
        ++d_subsets;
        size_t *last = find_if(begin, end, 
                                   bind2nd(not_equal_to<size_t>(), *begin));
        begin = last;
    }
}




