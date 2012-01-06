#include "dfarow.ih"

DFARow::DFARow(Rules &rules, 
               States &states, StateSetVector &stateSets, 
               size_t thisRowIdx, Ranges &ranges)
:
    d_finalRule(UINT_MAX, UINT_MAX),
    d_thisIdx(thisRowIdx),

    d_states(&states),
    d_stateSets(&stateSets),
    d_rules(&rules),
    d_ranges(&ranges)
{
    for (auto stateIdx: stateSets[thisRowIdx])
        probeTailCount(stateIdx);
}
