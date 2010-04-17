#include "generator.ih"

void Generator::transitions(DFARow const &row,
                    vector<pair<char, size_t>> &accept)
{
    for_each(row.begin(), row.end(), 
                FnWrap::unary(transition, out));

    addAccept(row, accept);
}
