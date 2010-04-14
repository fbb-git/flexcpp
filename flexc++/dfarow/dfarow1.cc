#include "dfarow.ih"

DFARow::DFARow(States const &states, StateSetVector &stateSets, 
               size_t thisIdx, size_t nRanges)
:
    d_states(&states),
    d_stateSets(&stateSets),
    d_thisIdx(thisIdx),
    d_nRanges(nRanges)
{}
