#include "larule.ih"

LARule::LARule(size_t ruleIdx)
:
    d_rule(ruleIdx),
    d_accept(-1),
    d_final(-2),
    d_inc(false)
{}
