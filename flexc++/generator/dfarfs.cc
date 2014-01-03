#include "generator.ih"

void Generator::dfaRFCs(DFARow const &row, ostream &out, 
                        vector<RuleFlag> &rf)
{
    out << setw(2) << rfc.size() << ',';        // begin index in s_rfc__

    auto final = row.final();

    for (auto &tail: row.tailCounts())
        storeRFC(tailCount, final, rfc);

    if (final.first != numeric_limits<size_t>::max())
        rfc.push_back(RuleFlag {final.first, FINAL | BOL});

    if (final.second != numeric_limits<size_t>::max())
        rfc.push_back(RuleFlag {final.second, FINAL});

    out << setw(2) << rfc.size();               // end index in s_rfc__
}







