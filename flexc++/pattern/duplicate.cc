#include "pattern.ih"

// Returns a Pattern which is a duplicate of the current pattern. It's a
// self-supporting pattern, i.e., in the returned pattern all its next1/next2
// links refer to the new pattern's states, and the StateData elements are
// deep copies.

Pattern Pattern::duplicate(States &states) const
{
    Map map;
    map[0] = 0;             // the end link remains as-is and is implicitly
                            // available 

    // the pair-indices of the new pattern are found in map[d_pair.first]
    // and map[d_pair.second];

    dupPattern(map, states, d_pair.first);

    return Pattern(Pair(map[d_pair.first], map[d_pair.second]));
}
