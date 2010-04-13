#include "ranges.ih"

void Ranges::reduce(vector<size_t> &ranges)
{
    for_each(d_ranges, d_ranges + d_size, FnWrap::unary(reassign, ranges));

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
