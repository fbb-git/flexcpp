#include "ranges.ih"

// All states are visited. 
//  If a state holds a plain character it is changed to
//      its character range number.
//  If a state holds a string, string.length() - 1 states are added
//      the state's content becomes the first character's range number,
//      remaining states hold the remaining characters' range numbers,
//      and the end-state copies the original end-state.
//          1 - abc - 2 - x becomes: 1 -a- 2 -b- 3 -c- 4 - x
//      and d_data(1,x) becomes d_data(1,x) 
// If a state holds a set consisting of characters in n character ranges
//  then the ranges are changed to the set of character range numbers.
//  There is no need to insert new states. When character is inspected it
//  determine from the range whether there is a transition to another state or
// not. 

void Ranges::finalizeStates()
{
    for_each(d_states.begin(), d_states.end(), 
                                FnWrap::unary(finalizeState, d_ranges));
}
