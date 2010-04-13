#include "charclass.ih"

spSemVal &CharClass::unite(spSemVal &lhs, SemVal const &rhs)
{
    downCast<CharClass>(*lhs).addSet(downCast<CharClass>(rhs).d_set);

    return lhs;
}
