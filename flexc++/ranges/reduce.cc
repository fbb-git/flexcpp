#include "usage.ih"

void Usage::reduce(vector<size_t> &ranges)
{
    for_each(d_usage, d_usage + d_size, FnWrap::unary(reassign, ranges));

    d_subsets = 1;
    for 
    (
        auto iter = d_usage + 1, end = d_usage + d_size; 
            iter != end;
                ++iter
    )
    {
        if (*(iter - 1) != *iter)
            ++d_subsets;
    }
}
