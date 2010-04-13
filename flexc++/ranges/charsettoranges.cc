#include "ranges.ih"

void Ranges::charsetToRanges(StateData &data, size_t *ranges)
{
    string const &str = SemVal::downCast<StateString>(data).str();

    set<size_t> rangeSet;
    for_each(str.begin(), str.end(), 
                            FnWrap::unary(addRangeNr, ranges, rangeSet));

    string next;
    copy(rangeSet.begin(), rangeSet.end(), inserter(next, next.end()));

    
    SemVal::downCast<StateString>(data).set(next);
}
