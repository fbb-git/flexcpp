#include "ranges.ih"

// update receives in next the new count of character occurrences.
// after correcting for collisions ...

void Ranges::update(string const &str, size_t const *next)
{
        // if pre- post- character range collisions
        // add next to ranges, otherwise copy next to ranges
        //    
    if (collision(str, next))       
        transform(d_ranges, d_ranges + d_size, next, d_ranges, plus<size_t>());
    else
        copy(next, next + d_size, d_ranges);

        // Determine the numbers used in the ranges, reduce the actual
        // d_range vaues by their indices in rangeNrs
    vector<size_t> rangeNrs;

    for_each(
        d_ranges, d_ranges + d_size, 
        [&](size_t &count)
        {
            countRanges(count, rangeNrs);
        }
    );

    subsetCount();                      // count the subsets
}



