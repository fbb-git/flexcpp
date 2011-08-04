#include "patternval.ih"

// Data:   pattern: the initial pattern
//         begin, end: the begin/end state indices of the initial pattern
//         beginEnd: vector of pairs holding begin and end indices of copied
//                   patterns
// 
// First the initial number of required patterns is duplicated (the 1st one 
//         already being available as it is `pattern' itself)
// 
// If the upper repetition limit is not set, make the last pattern repeatable,
//         (and join the patterns) and leave.
// 
// Otherwise: dup the remaining patterns, allocating an extra state to allow 
//         for exits in between the pattern boundaries. 
// 
// Once the remaining patterns are dupped, add their jumps to the end-state
// 
// Finally join all the patterns and return the begin-end states of the final
// (merged) pattern.

spSemVal PatternVal::copy(States &states, SemVal &semval, size_t lower, 
                                                            size_t upper)
{
    PatternVal &pattern = downCast<PatternVal>(semval); // the pattern to copy

    PairVector beginEnd(1, States::Pair{pattern.begin(), pattern.end()});   
                                                        // begin/end indices
                                                        // of all pattern

    copyPattern(states, lower - 1, beginEnd);           // copy req'd patterns

    return
        upper == UINT_MAX ?                 // no upper limit: optionally 
            optRepeatLastPattern(states,    // repeat the last pattern. 
                            pattern, lower, beginEnd)
        :                                   // Otherwise add fixed nr
            optionalPatterns(states, pattern,   // of optional patterns
                            lower, upper, beginEnd);
}



