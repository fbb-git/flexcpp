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
    for_each(
        stateSets[thisRowIdx].begin(), stateSets[thisRowIdx].end(),
        [this](size_t stateIdx)
        {
            this->probeTailCount(stateIdx);
        }
    );
}
