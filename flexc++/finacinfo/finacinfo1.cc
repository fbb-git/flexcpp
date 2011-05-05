#include "finacinfo.ih"

FinAcInfo::FinAcInfo(size_t ruleIdx, bool final)
:
    d_rule(ruleIdx),
    d_info(final ? FINAL_STATE : 0),
    d_accept(0)
{}
