#include "ranges.hh"

Ranges::Ranges(Ranges const &other)
:
    d_alphabet(new size_t[other.d_alphabetSize]),
    d_alphabetSize(other.d_alphabetSize),
    d_nRanges(other.d_nRanges),
    d_states(other.d_states)
{
    copy(other.d_alphabet, other.d_alphabet + d_alphabetSize, d_alphabet);
}
