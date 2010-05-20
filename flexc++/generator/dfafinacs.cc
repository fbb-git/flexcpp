#include "generator.ih"

void Generator::dfaFinAcs(DFARow const &row, ostream &out, 
                          vector<FinAcInfo> &finAcs)
{
    out << setw(2) << finAcs.size() << ',';

    for_each(row.finAcInfos().begin(), row.finAcInfos().end(), 
        FnWrap::unary(inspectFinAc, finAcs));

    out << setw(2) << finAcs.size();
}

