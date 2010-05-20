#include "finacinfo.ih"

FinAcInfo::FinAcInfo(size_t ruleIdx)
:
    d_rule(ruleIdx),
    d_accept(-1),
    d_final(-2),
    d_inc(false)
{}
