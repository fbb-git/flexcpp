#include "dfarow.ih"

DFARow::DFARow(Rules const &rules, 
               States &states, StateSetVector &stateSets, 
               size_t thisIdx, Ranges &ranges)
:
    d_states(&states),
    d_stateSets(&stateSets),
    d_rules(&rules),
    d_ranges(&ranges),
    d_thisIdx(thisIdx)
{
    for_each(stateSets[thisIdx].begin(), stateSets[thisIdx].end(),
             FnWrap::unary(insertLARule, *this));
}
