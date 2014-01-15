#include "ranges.ih"

void Ranges::determineSubsets()
{
    for(auto &state: d_states)
        inspectState(state);

    // now convert counts to ranges. At each transition increment the range 
    // nr. The initial range is 0

    size_t *begin = d_alphabet;
    size_t *end = d_alphabet + d_alphabetSize;
    size_t range = 0;
    while (begin != end)
    {
        size_t *last = find_if(begin, end, 
                                   bind2nd(not_equal_to<size_t>(), *begin));
        fill(begin, last, range++);
        begin = last;
    }
}
