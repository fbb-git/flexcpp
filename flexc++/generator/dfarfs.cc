#include "generator.ih"

void Generator::dfaRFs(DFARow const &row, ostream &out, 
                        vector<RuleFlag> &rf)
{
    auto final = row.final();

    size_t rule;
    size_t flag;

    if (final.first != numeric_limits<size_t>::max())
    {
        rule = final.first;
        flag = BOL | FINAL;
    }
    else if (final.second != numeric_limits<size_t>::max())
    {
        rule = final.second;
        flag = FINAL;
    }
    else
    {
        rule = 0;
        flag = 0;
    }

    out << setw(3) << rule << ", " << flag;
    
//    out << setw(2) << rf.size() << ',';        // begin index in s_rfc__
//
//    auto final = row.final();
//
//    if (final.first != numeric_limits<size_t>::max())
//        rf.push_back(RuleFlag {final.first, FINAL | BOL});
//
//    if (final.second != numeric_limits<size_t>::max())
//        rf.push_back(RuleFlag {final.second, FINAL});
//
//    out << setw(2) << rf.size();               // end index in s_rf__
}







