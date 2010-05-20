#include "finacinfo.ih"

FinAcInfo::FinAcInfo(size_t ruleIdx, Final final)
:
    d_rule(ruleIdx),
    d_accept(PRE_A_STATE),
    d_final(final),
    d_inc(false)
{}
