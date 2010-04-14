#include "dfarow.ih"

void DFARow::transitions(std::vector<std::set<size_t>> &stateSet,
                         set<size_t> const &rowSet, size_t nRanges)
{
    for_each(rowSet.begin(), rowSet.end(), 
                FnWrap::unary(transit(*this, stateSet, rowSet, nRanges)));
}
