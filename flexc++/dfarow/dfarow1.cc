#include "dfarow.ih"

DFARow::DFARow(Rules const &rules, 
               States const &states, StateSetVector &stateSets, 
               size_t thisIdx, Ranges &ranges)
:
    d_finalRule(UINT_MAX),
    d_states(&states),
    d_stateSets(&stateSets),
    d_rules(&rules),
    d_ranges(&ranges),
    d_thisIdx(thisIdx)
{}
