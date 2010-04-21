#include "generator.ih"

size_t Generator::addFinal(DFARow const &row,
                    vector<pair<size_t, size_t>> &final)
{
    copy(row.finalMap().begin(), row.finalMap().end(),
            back_inserter(final));

    return final.size();
}
