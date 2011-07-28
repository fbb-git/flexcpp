#include "patternval.ih"

#include <iostream>

void PatternVal::copyPattern(States &states, size_t count, 
                                                PairVector &beginEnd)
{
    size_t begin = beginEnd[0].first;
    size_t end = beginEnd[0].second;

    for (size_t idx = count; count--; )       // copy 'count' patterns
    {
        Map copied;     // a map is used to related old state indices (index)
                        // to new state indices (values). The value 0, 0
                        // indicates the end of  link and is always initially
                        // added. 
        copied[0] = 0;
                                                    // duplicate the pattern
        dupPattern(copied, states, begin);

cout << "Pattern " << idx << " starts at " << copied[begin] << 
", ends at " << copied[end] << '\n';

        beginEnd.push_back(States::Pair{copied[begin], copied[end]});
    }
}

