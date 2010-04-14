#include "ranges.ih"

void Ranges::add(string const &str)
{
    size_t *next = new size_t[d_size];
    
        // initialize next values with d_ranges
    copy(d_ranges, d_ranges + d_size, next);

        // increment next counts for chars in str
    for_each(str.begin(), str.end(), FnWrap::unary(incIf, next));

    updateRanges(str, next);

    delete [] next;
}
