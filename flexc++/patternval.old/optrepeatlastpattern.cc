#include "patternval.ih"

spSemVal PatternVal::optRepeatLastPattern(States &states, PatternVal &pattern,
                        size_t lower, PairVector &beginEnd)
{
    PatternVal last(beginEnd.back());

        // change the last pattern to pattern+
    spSemVal sp = plus(states, last);   

        // update the begin- and end-indices
    beginEnd.back() = downCast<PatternVal>(*sp).d_pair;

    join(states, pattern, lower, beginEnd);

//cout << "Last pattern repeatable: starts at " << rept.begin() << 
//", ends at " << rept.end() << '\n';
//
//        
//cout << "POST {x,}:\n" <<
//        states << '\n';

    spSemVal ret(new PatternVal( {pattern.begin(), pattern.end()} ));
    return ret;
}
