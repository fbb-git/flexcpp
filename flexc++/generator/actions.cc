#include "generator.ih"

void Generator::actions(ostream &out) const
{
    key(out);

    size_t idx = 0;

    // First handle the non-LOP rule actions:
    // this allows falling throug if rules are using OR actions

    for (auto &rule: ranger(d_rules.ruleBegin(), d_rules.ruleEnd()))
    {
        if (not rule.isLopRule())
            ruleAction(rule.block(), out, idx);
        else
            ++idx;
    }

    // Next handle the LOP rules themselves.

    idx = 0;

    for (auto &rule: ranger(d_rules.ruleBegin(), d_rules.ruleEnd()))
    {
        if (rule.isLopRule())
            ruleAction(rule.block(), out, idx);
        else
            ++idx;
    }

}
