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
    d_eof = d_subsets++;                    // always use the <<EOF>> range
    for_each(
        d_states.begin(), d_states.end(), 
        [this](State &state)
        {
            this->finalizeState(state);
        }
    );
    d_used = new bool[d_subsets];
    clearUsed();
}
