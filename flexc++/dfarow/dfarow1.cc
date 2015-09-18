#include "dfarow.hh"

DFARow::DFARow(Rules &rules, 
               States &states, StateSetVector &stateSets, 
               size_t thisRowIdx, size_t nRanges, vector<bool> *usedR)
:
    d_finalRule(max<size_t>(), max<size_t>()),
    d_thisIdx(thisRowIdx),

    d_states(&states),
    d_stateSets(&stateSets),
    d_rules(&rules),
    d_nRanges(nRanges),
    d_usedRanges(usedR)
{}
