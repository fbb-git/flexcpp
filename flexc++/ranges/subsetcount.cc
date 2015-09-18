#include "ranges.hh"

void Ranges::subsetCount()
{
    d_nRanges = 0;

    size_t *begin = d_alphabet;
    size_t *end = d_alphabet + d_alphabetSize;
    while (begin != end)
    {
        ++d_nRanges;
        size_t *last = find_if(begin, end, 
                                   bind2nd(not_equal_to<size_t>(), *begin));
        begin = last;
    }
}




