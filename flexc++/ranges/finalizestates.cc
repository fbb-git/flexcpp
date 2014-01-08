#include "ranges.ih"

// All states are visited. 
//  If a state holds a plain character it is changed to
//      its character range number.
// If a state holds a set consisting of characters in n character ranges
//  then the ranges are changed to the set of character range numbers.
//  There is no need to insert new states. When character is inspected it
//  determine from the range whether there is a transition to another state or
// not. 

void Ranges::finalizeStates()
{
                                    // always use the <<EOF>> range
    d_eof = d_nRanges == 0 ? ++d_nRanges : d_nRanges++;

    for(auto &state: d_states)
        finalizeState(state);

    d_used = new bool[d_nRanges];
    clearUsed();
}
