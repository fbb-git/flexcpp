#include "ranges.hh"

void Ranges::charsetToRanges(StateData &data, size_t *ranges)
{
    string const &str = data.str();

    set<size_t> rangeSet;               // determine the ranges of the chars
                                        // used in the string
    for(auto ch:  str)
        rangeSet.insert(ranges[static_cast<unsigned char>(ch)]);

    string next;                        // create a new string
    copy(rangeSet.begin(), rangeSet.end(), inserter(next, next.end()));

    data.set(next);                     // assign the string of range-nrs
                                        // to the state
}
