#include "patternval.ih"

void PatternVal::join(States &states, PatternVal &pattern, size_t upper,
                        PairVector const &beginEnd)
{
    PatternVal next;
    for (size_t idx = 1; idx != upper; ++idx)
    {
        next.d_pair = beginEnd[idx];

        pattern = downCast<PatternVal>(*concatenate(states, pattern, next));
    }
}
