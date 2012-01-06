#include "ranges.ih"

void Ranges::add(string const &str)
{
    size_t *next = new size_t[d_size];
    
        // initialize next values with d_ranges
    copy(d_ranges, d_ranges + d_size, next);

        // increment next counts for chars in str
    for (auto &ch: str)
        ++next[static_cast<unsigned char>(ch)];

    update(str, next);

    delete [] next;
}


