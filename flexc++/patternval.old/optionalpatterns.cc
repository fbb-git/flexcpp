#include "patternval.ih"

spSemVal PatternVal::optionalPatterns(States &states, PatternVal &pattern,
                                    size_t lower, size_t upper, 
                                    PairVector &beginEnd)
{
        // dup the remaining patterns, allowing for intermediate ejects
    Map eject;
    copyPattern(states, lower, upper, eject, beginEnd);

        // add jumps to the end of the pattern dupped last
    jumpToEnd(states, beginEnd, lower, upper, eject);

        // join all patterns, the first pattern being `pattern' (=semval)
    join(states, pattern, upper, beginEnd);

        // begin/end must be updated to the final indices
    spSemVal ret(new PatternVal( {pattern.begin(), pattern.end()} ));

    return ret;
}





