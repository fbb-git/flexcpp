#include "generator.ih"

void Generator::dfaRFs(DFARow const &row, ostream &out, 
                        vector<RuleFlag> &rf)
{
    auto final = row.final();

//    size_t rule;
//    size_t flag;
//
//    if (final.first != numeric_limits<size_t>::max())
//    {
//        rule = final.first;
//        flag = BOL | FINAL;
//    }
//    else if (final.second != numeric_limits<size_t>::max())
//    {
//        rule = final.second;
//        flag = FINAL;
//    }
//    else
//    {
//        rule = 0;
//        flag = 0;
//    }
//
//    out << setw(3) << rule << ", " << flag;

    int nonBolRule = -1;
    int bolRule = -1;

    if (final.first != numeric_limits<size_t>::max())
        bolRule = final.first;

    if (final.second != numeric_limits<size_t>::max())
        nonBolRule = final.second;

    out << setw(3) << nonBolRule << ',' << setw(3) << bolRule;

}







