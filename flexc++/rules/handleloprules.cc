#include "rules.ih"

void Rules::handleLopRules()
{
    setLopBlocks();     // make sure each LOP rule gets its own action block

    for (size_t idx = 0, nRules = d_rules.size(); idx != nRules; ++idx)
        handleLopRule(d_rules[idx]);
}
