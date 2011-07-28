#include "patternval.ih"

//////////////////////////
#include <iostream>
#include <bobcat/errno>

spSemVal PatternVal::optionalPatterns(States &states, PatternVal &pattern,
                                    size_t lower, size_t upper, 
                                    PairVector &beginEnd)
{
cout << "Optionally: " << lower << " to " << upper << '\n';
        // dup the remaining patterns, allowing for intermediate ejects
    Map eject;
    copyPattern(states, lower, upper, eject, beginEnd);

        // add jumps to the end of the pattern dupped last
    jumpToEnd(states, beginEnd, lower, upper, eject);

        // join all patterns, the first pattern being `pattern' (=semval)
    join(states, pattern, upper, beginEnd);

cout << "POST:\n" <<
        states << '\n';

    throw Errno("copy2 completed\n");

        // begin/end must be updated to the final indices
    spSemVal ret(new PatternVal( {pattern.begin(), pattern.end()} ));
    return ret;
    
}





