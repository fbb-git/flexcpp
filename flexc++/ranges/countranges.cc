#include "ranges.hh"

void Ranges::countRanges(size_t &count, vector<size_t> &ranges)
{
    auto iter = find(ranges.begin(), ranges.end(), count);
    
    if (iter == ranges.end())
    {
        ranges.push_back(count);
        count = ranges.size() - 1;
        return;
    }

    count = iter - ranges.begin();
}
