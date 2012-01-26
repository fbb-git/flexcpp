#include "pattern.ih"

Pattern Pattern::optRepeatLastPattern(States &states, 
                        Pattern &pattern,
                        size_t lower, PairVector &beginEnd)
{
    Pattern last(beginEnd.back());

        // change the last pattern to pattern+
        // update the begin- and end-indices
    beginEnd.back() = plus(states, last).d_pair;

    join(states, pattern, lower, beginEnd);

//cout << "Last pattern repeatable: starts at " << rept.begin() << 
//", ends at " << rept.end() << '\n';
//
//        
//cout << "POST {x,}:\n" <<
//        states << '\n';

    Pattern ret( {pattern.begin(), pattern.end()} );
    return ret;
}
