#include "dfarow.ih"

// unordered maps do not support operator==, we have to do it ourselves.
// The transitions are only stored if available, so the sizes of the
// transition vectors may differ. In that case the transitions are of course
// unequal.

bool DFARow::sameTransits(
            FBB::LinearMap<size_t, size_t> const &lhs,
            FBB::LinearMap<size_t, size_t> const &rhs)
{
    if (lhs.size() != rhs.size())
        return false;

        // visit all elements of the lhs container
    for (auto lhsIter = lhs.begin(); lhsIter != lhs.end(); ++lhsIter)
    {
            // find the key in the rhs container
        auto rhsIter = rhs.find(lhsIter->first);

            // not equal if the key isn't found or if the value isn't equal
        if (rhsIter == rhs.end() || lhsIter->second != rhsIter->second)
            return false;
    }
    return true;
}



