#include "rules.hh"

void Rules::setLopBlocks()
{
    // the last rule always has a (possibly empty) block.
    // visit all blocks from the last until the first
    for (
        size_t idx = d_rules.size(), actionIdx = idx, lopIdx = idx;
            idx-- != 0;
                // canonical decrement           
    )
    {
        Rule &rule = d_rules[idx];

        RuleType type = rule.type();
        if (type == RuleType::LOP_1 or type == RuleType::LOP_FIXED)
        {
            lopIdx = idx;       // remember the last LOP rule

            if (rule.orAction())
                rule.assignBlock(d_rules[actionIdx].block());
            else
                actionIdx = idx;
        }
        else if (not rule.orAction())   // normal rule
            actionIdx = idx;
        else if (lopIdx == actionIdx)
        {
            rule.assignBlock(d_rules[lopIdx].block());
            actionIdx = idx;
        }
    }
}


