#include "dfarow.ih"

void DFARow::setViable(size_t *destIdx, size_t ruleIdx)
{

//if (*destIdx == max<size_t>())
//cerr << "       set "<< ruleIdx << " (" << (*d_rules)[ruleIdx].type() << ")\n";
//else    
//cerr << "       replace " << *destIdx << " (" << (*d_rules)[*destIdx].type() <<    
//") by " << ruleIdx << " (" << (*d_rules)[ruleIdx].type() << ")\n";

    if (*destIdx != max<size_t>())              // unset the viable state of 
        (*d_rules)[*destIdx].setViable(false);  // the previously set rule

    (*d_rules)[ruleIdx].setViable(true);        // new rule now viable

    *destIdx = ruleIdx;
}
