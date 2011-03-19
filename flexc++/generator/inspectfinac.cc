#include "generator.ih"

// add to finAcs if:
//  - the finac refers to an incrementing tail
//  - the finac refers to a FINAL state, and there isn't a final state yet.

void Generator::inspectFinAc(FinAcInfo const &finac, 
                             vector<FinAcInfo> &finAcs,
                             int &finalRule)
{
    if (finac.inc())
    {
        finAcs.push_back(finac);
        return;
    }

    if 
    (
        finalRule != -1
        ||
        finac.final() == FinAcInfo::NOT_FINAL
    )
        return;
    
    finalRule = finac.rule();       // accept the first matching pattern
    finAcs.push_back(finac);
}
