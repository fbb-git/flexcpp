#include "pattern.hh"

Pattern Pattern::optRepeatLastPattern(States &states, 
                        Pattern &pattern,
                        size_t lower, PairVector &beginEnd)
{
    Pattern last(beginEnd.back());

        // change the last pattern to pattern+
        // update the begin- and end-indices
    beginEnd.back() = plus(states, last).d_pair;

    join(states, pattern, lower, beginEnd);

    Pattern ret( {pattern.begin(), pattern.end()} );
    return ret;
}
