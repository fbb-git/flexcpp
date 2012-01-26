#include "pattern.ih"

void Pattern::join(States &states, Pattern &pattern, size_t upper,
                        PairVector const &beginEnd)
{
    Pattern next;

    for (size_t idx = 1; idx != upper; ++idx)
    {
        next.d_pair = beginEnd[idx];
        pattern = concatenate(states, pattern, next);
    }
}
