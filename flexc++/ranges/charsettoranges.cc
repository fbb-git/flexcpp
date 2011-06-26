#include "ranges.ih"

void Ranges::charsetToRanges(StateData &data, size_t *ranges)
{
    string const &str = SemVal::downCast<StateString>(data).str();

    set<size_t> rangeSet;               // determine the ranges of the chars
                                        // used in the string
    for_each(
        str.begin(), str.end(),    
        [&, ranges](char ch)
        {
            rangeSet.insert(ranges[static_cast<unsigned char>(ch)]);
        }
    );

    string next;                        // create a new string
    copy(rangeSet.begin(), rangeSet.end(), inserter(next, next.end()));

                                        // assign the string of range-nrs
                                        // to the state
    SemVal::downCast<StateString>(data).set(next);
}
