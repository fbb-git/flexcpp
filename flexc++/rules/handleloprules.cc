#include "rules.ih"

void Rules::handleLopRules()
{
    setLopBlocks();     // make sure each LOP rule gets its own action block

        // handleLopRule may extend d_rules, but will never add another LOP
        // rule. That's why d_rules.size() can be used.

    vector<size_t> lopIndices;

    for (size_t idx = 0, nRules = d_rules.size(); idx != nRules; ++idx)
    {
        if (d_rules[idx].isLopRule())
        {
            handleLopRule(idx);
            lopIndices.push_back(idx);
        }
    }

    size_t catchAllIndex = d_rules.size();

    add(false, d_catchAll.pattern(), d_catchAll.block(), RuleType::LOP_3);

    for (size_t idx: lopIndices)
        addCatchAll(d_rules[idx], catchAllIndex);
}








