#include "rules.ih"

size_t Rules::ruleFromFinalState(size_t stateIdx) const
{
    size_t rule = d_finalToRule.find(stateIdx)->second;

    auto iter = d_lopToRule.find(rule);

    return d_userSC && iter != d_lopToRule.end() ?
                iter->second
            :
                rule;
}

