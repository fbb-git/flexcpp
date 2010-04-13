#include "ranges.ih"

void Ranges::updateRanges(string const &str, size_t const *next)
{
        // if pre- post- character range collisions
        // add next to ranges, otherwise copy next to ranges
        //    
    if (collision(str, next))       
        transform(d_ranges, d_ranges + d_size, next, d_ranges, plus<size_t>());
    else
        copy(next, next + d_size, d_ranges);
    
        // Determine the ranges
        //
    vector<size_t> rangeNrs;
    for_each(d_ranges, d_ranges + d_size, FnWrap::unary(countRanges, rangeNrs));

    reduce(rangeNrs);                     // reduce d_ranges
}



