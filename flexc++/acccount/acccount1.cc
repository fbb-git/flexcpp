#include "acccount.ih"

AccCount::AccCount(size_t ruleIdx, State::Flag flag)
:
    d_rule(ruleIdx),
    d_type(DEFAULT),
    d_accCount(0)
{
    addFlag(flag);
}
