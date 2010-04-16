#include "ranges.ih"

// And individual element in the current d_ranges array is replaced by 
// its index in the rangeNr vector

void Ranges::reassign(size_t &count, vector<size_t> &rangeNrs)
{
    auto iter = find(rangeNrs.begin(), rangeNrs.end(), count);

    if (iter != rangeNrs.end())
        count = iter - rangeNrs.begin();
    else
    {
        count = rangeNrs.size();
        rangeNrs.push_back(count);
    }
}
