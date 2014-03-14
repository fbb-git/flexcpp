#include "dfarow.ih"

void DFARow::updateViable(size_t *destIdx, size_t ruleIdx)
{
//
//    if (
//        ruleIdx < *destIdx                          // current rule before
//        ||                                          // other rule
//        *destIdx == max<size_t>()                   // rule not yet set
//    ) 
//        setViable(destIdx, ruleIdx);

    if (*destIdx == max<size_t>())               // rule not yet set
        setViable(destIdx, ruleIdx);
    else
    {
        RuleType destType = (*d_rules)[*destIdx].type();
        RuleType ruleType = (*d_rules)[ruleIdx].type();

        if (                                    // equal types, earlier rule
            (destType == ruleType && ruleIdx < *destIdx) 
            ||                                  // or later rule is NORMAL
            (ruleType == RuleType::NORMAL && destType != RuleType::NORMAL)
        )
            setViable(destIdx, ruleIdx);
    }

}






