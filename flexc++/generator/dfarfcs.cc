#include "generator.ih"

void Generator::dfaRFCs(DFARow const &row, ostream &out, 
                        vector<RuleFlagCount> &rfc)
{
    out << setw(2) << rfc.size() << ',';        // begin index in s_rfc

    pair<size_t, size_t> final = row.final();

    for_each(row.tailCounts().begin(), row.tailCounts().end(), 
             FnWrap::unary(storeRFC, final, rfc));

    if (final.first != UINT_MAX)
        rfc.push_back(RuleFlagCount {final.first, FINAL | BOL, 0});

    if (final.second != UINT_MAX)
        rfc.push_back(RuleFlagCount {final.second, FINAL, 0});

    out << setw(2) << rfc.size();               // end index in s_rfc
}







