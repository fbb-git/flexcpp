#include "dfarow.ih"

void DFARow::mergeFinal(size_t rule, vector<FinAcInfo> &finAcInfo)
{
    auto iter = find(finAcInfo.begin(), finAcInfo.end(), rule);

    if (iter == finAcInfo.end())
    {
        finAcInfo.push_back(FinAcInfo(rule));
        finAcInfo.back().setFinal(FinAcInfo::PLAIN_FINAL);
    }
    else
        cerr << "Final = " << iter->final() << endl;
}
