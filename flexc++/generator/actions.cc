#include "generator.ih"

void Generator::actions(ostream &out) const
{
    key(out);

    size_t idx = 0;

    for_each(
        d_rules.ruleBegin(), d_rules.ruleEnd(),
        [&](Rule const &rule)
        {
            ruleAction(rule, out, idx, d_lineDirectives);
        }
    );
}
