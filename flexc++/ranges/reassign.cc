#include "usage.ih"

void Usage::reassign(size_t &count, vector<size_t> &ranges)
{
    auto iter = find(ranges.begin(), ranges.end(), count);

    if (iter == ranges.end())
        ranges.push_back(count);
    
    count = iter - ranges.begin();
}
