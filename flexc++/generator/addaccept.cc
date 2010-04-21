#include "generator.ih"

size_t Generator::addAccept(DFARow const &row, PVector &accept)
{
    copy(row.acceptMap().begin(), row.acceptMap().end(),
            back_inserter(accept));

    return accept.size();
}
