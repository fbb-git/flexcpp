#include "ranges.ih"

Ranges::Ranges(Ranges &&tmp)
:
    d_alphabet(tmp.d_alphabet),
    d_alphabetSize(tmp.d_alphabetSize),
    d_nRanges(tmp.d_nRanges),
    d_states(tmp.d_states),
    d_used(tmp.d_used)
{
    tmp.d_alphabet = 0;
    tmp.d_used = 0;
}
