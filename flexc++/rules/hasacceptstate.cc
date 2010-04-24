#include "rules.ih"

int Rules::hasAcceptState(size_t stateIdx) const
{
    auto iter = d_reverseAccept.find(stateIdx);

    return iter == d_reverseAccept.end() ? -1 : iter->second;
}

