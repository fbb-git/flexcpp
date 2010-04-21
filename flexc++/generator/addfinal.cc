#include "generator.ih"

size_t Generator::addFinal(DFARow const &row,
                    vector <size_t> &final)
{
    copy(row.final().begin(), row.final().end(), back_inserter(final));

    return final.size();
}
