#include "rules.ih"

void Rules::handleLopRules()
{
    setLopBlocks();     // make sure each LOP rule gets its own action block

    if (d_hasFixedTailLOPrules)
    {
        for (auto &rule: d_rules)
        {
            if (rule.type() == RuleType::LOP_FIXED)
                handleFixedTailLopRule(rule);
        }
    }

    if (not d_hasVariableTailLOPrules)
        return;

        // handleLopRule may extend d_rules, but will never add another LOP
        // rule. That's why d_rules.size() can be used.

    vector<size_t> catchAllSCs;

    for (size_t idx = 0, nRules = d_rules.size(); idx != nRules; ++idx)
    {
        if (d_rules[idx].type() == RuleType::LOP_1)
            catchAllSCs.push_back(handleLopRule(idx));
    }

        // do not add the next rule to any start condition:
    d_startConditions.acceptRules(false);

        // determine the catch-all rule index, and add it to d_rules:
    size_t catchAllRuleIndex = d_rules.size();
    add(false, d_catchAll.pattern(), d_catchAll.block(), RuleType::LOP_3);

    d_startConditions.acceptRules(true);

        // add the catch-all rule to the appropriate SCs
    for (size_t idx: catchAllSCs)
        addCatchAll(idx, catchAllRuleIndex);
}


