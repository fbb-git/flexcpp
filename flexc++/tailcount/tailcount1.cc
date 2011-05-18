#include "tailcount.ih"

TailCount::TailCount(size_t ruleIdx, State::Flag flag)
:
    d_rule(ruleIdx),
    d_type(DEFAULT),
    d_tailCount(0)
{
    addFlag(flag);
}
