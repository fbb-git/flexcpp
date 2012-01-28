#include "rules.ih"

void Rules::noActions()
{
    for(auto &rule: ranger(d_rules.rbegin() + 1, d_rules.rend()))
    {
        if (not rule.orAction())
            break;

        rule.noAction();
    }
}
