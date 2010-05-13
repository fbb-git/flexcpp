//X#include "rules.ih"
//X
//Xint Rules::hasAcceptState(size_t stateIdx) const
//X{
//X    auto iter = d_reverseAccept.find(stateIdx);
//X
//X    return iter == d_reverseAccept.end() ? -1 : iter->second;
//X}
//X
