#include "dfarow.ih"

bool DFARow::sameTransits(
            std::unordered_map<size_t, size_t> const &lhs,
            std::unordered_map<size_t, size_t> const &rhs)
{
    for (auto lhsIter = lhs.begin(); lhsIter != lhs.end(); ++lhsIter)
    {
        auto rhsIter = rhs.find(lhsIter->first);
        if (rhsIter != rhs.end() && lhsIter->second != rhsIter->second)
            return false;
    }
    return true;
}
