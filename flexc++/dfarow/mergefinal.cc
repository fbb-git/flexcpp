#include "dfarow.ih"

void DFARow::mergeFinal(size_t rule, vector<FinAc> &finAc)
{
    if (find(finAc.begin(), finAc.end(), rule) == finAc.end())
        finAc.push_back(FinAc(rule, true));
}
