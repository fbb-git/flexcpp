#include "generator.ih"

void Generator::inspectFinAc(FinAcInfo const &finac, 
                             vector<FinAcInfo> &finAcs)
{
    if 
    (
        finac.final() != FinAcInfo::NOT_FINAL 
        ||
        finac.inc()
    )
        finAcs.push_back(finac);
}
