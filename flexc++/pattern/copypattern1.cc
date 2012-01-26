#include "pattern.ih"

void Pattern::copyPattern(States &states, size_t count, 
                                                PairVector &beginEnd)
{
    size_t begin = beginEnd[0].first;
    size_t end = beginEnd[0].second;

    for ( ; count--; )       // copy 'count' patterns
    {
        Map copied;     // a map is used to related old state indices (index)
                        // to new state indices (values). The value 0, 0
                        // indicates the end of  link and is always initially
                        // added. 
        copied[0] = 0;

                                                    // duplicate the pattern
        dupPattern(copied, states, begin);

        beginEnd.push_back(States::Pair{copied[begin], copied[end]});
    }
}

