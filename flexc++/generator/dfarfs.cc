#include "generator.ih"

void Generator::dfaRFs(DFARow const &row, ostream &out, 
                        vector<RuleFlag> &rf)
{
    out << setw(2) << rf.size() << ',';        // begin index in s_rfc__

    auto final = row.final();

    if (final.first != numeric_limits<size_t>::max())
        rf.push_back(RuleFlag {final.first, FINAL | BOL});

    if (final.second != numeric_limits<size_t>::max())
        rf.push_back(RuleFlag {final.second, FINAL});

    out << setw(2) << rf.size();               // end index in s_rf__
}







