#include "ranges.ih"

Ranges::Ranges(Ranges const &other)
:
    d_alphabet(new size_t[other.d_alphabetSize]),
    d_alphabetSize(other.d_alphabetSize),
    d_nRanges(other.d_nRanges),
    d_states(other.d_states),
    d_usedRanges(new bool[other.d_nRanges])
{
    copy(other.d_alphabet, other.d_alphabet + d_alphabetSize, d_alphabet);
    copy(other.d_usedRanges, other.d_usedRanges + d_nRanges, d_usedRanges);
}
