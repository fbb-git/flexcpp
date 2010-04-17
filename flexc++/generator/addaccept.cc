#include "generator.ih"

size_t Generator::addAccept(DFARow const &row,
                    vector<pair<size_t, size_t>> &accept)
{
    copy(row.acceptMap().begin(), row.acceptMap().end(),
            back_inserter(accept));

    return accept.size();
}
