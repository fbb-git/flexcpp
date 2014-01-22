#include "dfarow.ih"

void DFARow::updateViable(size_t &destIdx, size_t ruleIdx)
{
    if (destIdx <= ruleIdx)             // keep the lowest rule index
        return;

    if (destIdx != numeric_limits<size_t>::max())   // unset the viable state 
        (*d_rules)[destIdx].setViable(false);   // of the previously set rule

    (*d_rules)[ruleIdx].setViable(true);        // new rule now viable

    destIdx = ruleIdx;                          // remember the rule index
}

void DFARow::setFinal(size_t ruleIdx)
{
    updateViable(
        (*d_rules)[ruleIdx].bol() ? d_finalRule.second : d_finalRule.first, 
        ruleIdx
    );
}




