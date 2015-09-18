#include "ranges.hh"

Ranges::Ranges(Ranges &&tmp)
:
    d_alphabet(tmp.d_alphabet),
    d_alphabetSize(tmp.d_alphabetSize),
    d_nRanges(tmp.d_nRanges),
    d_states(tmp.d_states)
{
    tmp.d_alphabet = 0;
}
