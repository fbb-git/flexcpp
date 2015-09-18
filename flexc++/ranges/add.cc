#include "ranges.hh"

void Ranges::add(string const &str)
{
    size_t *next = new size_t[d_alphabetSize];
    
        // initialize next values with d_alphabet
    copy(d_alphabet, d_alphabet + d_alphabetSize, next);

        // increment next counts for chars in str
    for (auto &ch: str)
        ++next[static_cast<unsigned char>(ch)];

    update(str, next);

    delete [] next;
}


