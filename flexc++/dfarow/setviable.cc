#include "dfarow.ih"

void DFARow::setViable(size_t *destIdx, size_t ruleIdx)
{
    if (*destIdx != max<size_t>())              // unset the viable state of 
        (*d_rules)[*destIdx].setViable(false);  // the previously set rule

    (*d_rules)[ruleIdx].setViable(true);        // new rule now viable

    *destIdx = ruleIdx;
}
