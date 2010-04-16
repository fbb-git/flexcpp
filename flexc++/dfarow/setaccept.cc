#include "dfarow.ih"

void DFARow::setAccept(size_t stateIdx)
{
    size_t rule = d_rules->hasAcceptState(stateIdx);

    if (d_acceptRules.find(rule) == d_acceptRules.end())
        d_acceptRules[rule] = State::NON_INHERITING;
}
