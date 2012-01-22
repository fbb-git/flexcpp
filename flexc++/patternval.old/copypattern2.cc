#include "patternval.ih"

void PatternVal::copyPattern(States &states, size_t lower, size_t upper, 
                                Map &eject, PairVector &beginEnd)
{
    size_t begin = beginEnd[0].first;

    for (size_t idx = lower; idx != upper; ++idx)  // copy 'up - lo' patterns
    {
        Map copied;     // a map is used to related old state indices (index)
                        // to new state indices (values). The value 0, 0
                        // indicates the end of  link and is always initially
                        // added. 
        copied[0] = 0;
                                                    // duplicate the pattern
        dupPattern(copied, states, begin);


        beginEnd.push_back(States::Pair{copied[begin], 
                                        copied[beginEnd[0].second]});

        size_t first = states.next();

        eject[idx] = first;             // 1st state of pattern[idx] will be
                                        // 'first'
    }
}

