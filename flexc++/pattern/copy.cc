#include "pattern.ih"

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

Pattern Pattern::copy(States &states, 
                      Pattern &regex, size_t lower, size_t upper)
{
    PairVector beginEnd(1, Pair{regex.begin(), regex.end()});   
                                                        // begin/end indices
                                                        // of the regex

    copyPattern(states, lower - 1, beginEnd);           // copy req'd patterns

    return
        upper == numeric_limits<size_t>::max() ?    // no upper limit: 
            optRepeatLastPattern(states,            // optionally  repeat the 
                            regex, lower, beginEnd) // last pattern. 
        :                                       // Otherwise add fixed nr
            optionalPatterns(states, regex,     // of optional patterns
                            lower, upper, beginEnd);
}


