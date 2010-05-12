#include "rules.ih"

void Rules::propagate(Rule const &rule, States &states)
{
    states.propagateAccept(rule.accept(), 0);
}
