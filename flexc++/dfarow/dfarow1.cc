#include "dfarow.ih"

DFARow::DFARow(Rules &rules, 
               States &states, StateSetVector &stateSets, 
               size_t thisRowIdx, size_t nRanges, vector<bool> *usedR)
:
    d_finalRule(numeric_limits<size_t>::max(), numeric_limits<size_t>::max()),
    d_thisIdx(thisRowIdx),

    d_states(&states),
    d_stateSets(&stateSets),
    d_rules(&rules),
    d_nRanges(nRanges),
    d_usedRanges(usedR)
{}
