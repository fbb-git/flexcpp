#include "ranges.ih"

Ranges::Ranges(States &states, size_t size)
:
    d_alphabet(new size_t[size]),
    d_alphabetSize(size),
    d_nRanges(0),
    d_bol(0),
    d_eof(0),
    d_states(states),
    d_usedRanges(0)
{
    fill(d_alphabet, d_alphabet + d_alphabetSize, 0);
}
