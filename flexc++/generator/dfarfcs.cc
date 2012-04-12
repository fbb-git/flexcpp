#include "generator.ih"

void Generator::dfaRFCs(DFARow const &row, ostream &out, 
                        vector<RuleFlagCount> &rfc)
{
    out << setw(2) << rfc.size() << ',';        // begin index in s_rfc__

    auto final = row.final();

    for (auto &tailCount: row.tailCounts())
        storeRFC(tailCount, final, rfc);

    if (final.first != numeric_limits<size_t>::max())
        rfc.push_back(RuleFlagCount {final.first, FINAL | BOL, 0});

    if (final.second != numeric_limits<size_t>::max())
        rfc.push_back(RuleFlagCount {final.second, FINAL, 0});

    out << setw(2) << rfc.size();               // end index in s_rfc__
}







