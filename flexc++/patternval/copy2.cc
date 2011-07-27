#ifndef INCLUDED_COPY2_CC_
#define INCLUDED_COPY2_CC_

#include "patternval.ih"

////////////////////////////////
#include <iostream>
#include <bobcat/errno>

spSemVal PatternVal::copy(States &states, SemVal &semval, size_t lower, 
                                                            size_t upper)
{
    cout << "Calling copy for " << lower << " to " << upper << '\n';

cout << "PRE:\n" <<
        states << '\n';

    PatternVal &pattern = downCast<PatternVal>(semval); // the pattern to copy

    size_t begin = pattern.begin();     // remember its begin/end states
    size_t end  = pattern.end();

        // A vector of pairs is used to retrieve the begin/end State indices
        // of the original and copied patterns
    vector<States::Pair> beginEnd(1, States::Pair{begin, end});

    for (size_t idx = 1; idx != lower; ++idx)       // copy the initial
    {                                               // required patterns

        Map copied;     // a map is used to related old state indices (index)
                        // to new state indices (values). The value 0, 0
                        // indicates the end of  link and is always initially
                        // added. 
        copied[0] = 0;
                                                    // copy the pattern
        copyPattern(copied, states, pattern.begin());

cout << "Pattern " << idx << " starts at " << copied[begin] << 
", ends at " << copied[end] << '\n';

        beginEnd.push_back(States::Pair{copied[begin], copied[end]});        
    }


    spSemVal ret;

// TO DO:
//    if (upper == UINT_MAX)          // no upper limit: optionally cycle back
//    {
//        Map &map = copied.back();     // the last map
//
//                                                // begin/end states
//        PatternVal last(States::Pair{map[begin], map[end]});    
//
//        spSemVal sp = plus(states, last);   // change to pattern+
//        PatternVal &rept = downCast<PatternVal>(*sp);
//
//        map[begin] = rept.begin();
//        map[end] = rept.end();
//
//cout << "Last pattern repeatable: starts at " << rept.begin() << 
//", ends at " << rept.end() << '\n';
//
//        
//cout << "POST {x,}:\n" <<
//        states << '\n';
//
//    throw Errno("copy2 completed\n");
//
//    }        
        
cout << "Optionally: " << lower << " to " << upper << '\n';

    Map optionals;

    for (size_t idx = lower; idx != upper; ++idx)   // copy the remaining
    {                                               // optional patterns
        Map copied;
        copied[0] = 0;
                                                    // copy the pattern
        copyPattern(copied, states, pattern.begin());

        beginEnd.push_back(States::Pair{copied[begin], copied[end]});        


        size_t first = states.next();

cout << "Pattern " << idx << " starts at " << copied[begin] << 
", ends at " << copied[end] << ", prefixing state " << first << '\n';

        optionals[idx] = first;         // 1st state of pattern[idx] becomes
                                        // first
    }

    size_t finalState = beginEnd.back().second;

    for (size_t idx = lower; idx != upper; ++idx)   // set the optionals to
    {                                               // the end-state
        states[optionals[idx]] = 
            State::factory(State::EMPTY, beginEnd[idx].first, finalState);

        beginEnd[idx].first = optionals[idx];    // new begin state
    }


    // catenate all states, the first pattern is `pattern' (=semval)
    PatternVal next;
    for (size_t idx = 1; idx != upper; ++idx)
    {
        next.d_pair = beginEnd[idx];

        spSemVal sp = concatenate(states, pattern, next);
        pattern = downCast<PatternVal>(*sp);
    }

cout << "POST:\n" <<
        states << '\n';

    throw Errno("copy2 completed\n");

        // begin/end must be updated to the final indices
    ret = spSemVal(new PatternVal( {pattern.begin(), pattern.end()} ));
    return ret;
    
}


#endif





