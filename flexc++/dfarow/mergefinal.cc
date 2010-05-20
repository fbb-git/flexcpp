#include "dfarow.ih"

void DFARow::mergeFinal(size_t rule, vector<FinAcInfo> &finAcInfo)
{
    if (find(finAcInfo.begin(), finAcInfo.end(), rule) == finAcInfo.end())
        finAcInfo.push_back(FinAcInfo(rule, FinAcInfo::FINAL_NOT_SET));
}
