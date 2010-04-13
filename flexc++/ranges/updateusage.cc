#include "usage.ih"

void Usage::updateUsage(string const &str, size_t const *next)
{
        // if pre- post- character range collisions
        // add next to usage, otherwise copy next to usage
        //    
    if (collision(str, next))       
        transform(d_usage, d_usage + d_size, next, d_usage, plus<size_t>());
    else
        copy(next, next + d_size, d_usage);
    
        // Determine the ranges
        //
    vector<size_t> ranges;
    for_each(d_usage, d_usage + d_size, FnWrap::unary(countRanges, ranges));

    reduce(ranges);                     // reduce d_usage
}



