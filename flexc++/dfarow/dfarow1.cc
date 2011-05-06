#include "dfarow.ih"

DFARow::DFARow(Rules &rules, 
               States &states, StateSetVector &stateSets, 
               size_t thisRowIdx, Ranges &ranges)
:
    d_finalRule(UINT_MAX, UINT_MAX),
    d_states(&states),
    d_stateSets(&stateSets),
    d_rules(&rules),
    d_ranges(&ranges),
    d_thisIdx(thisRowIdx)
{
    for_each(stateSets[thisRowIdx].begin(), stateSets[thisRowIdx].end(),
             FnWrap::unary(insertFinAcInfo, *this));
}
