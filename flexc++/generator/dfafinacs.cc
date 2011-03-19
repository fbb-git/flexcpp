#include "generator.ih"

void Generator::dfaFinAcs(DFARow const &row, ostream &out, 
                          vector<FinAcInfo> &finAcs)
{
    out << setw(2) << finAcs.size() << ',';     // begin index in s_finacs

    int finalRule = -1;                         // no final rule as yet

    for_each(row.finAcInfos().begin(), row.finAcInfos().end(), 
        FnWrap::unary(inspectFinAc, finAcs, finalRule));

    out << setw(2) << finAcs.size();            // end index in s_finacs
}

