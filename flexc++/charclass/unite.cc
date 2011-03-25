#include "charclass.ih"

spSemVal &CharClass::unite(spSemVal &lhs, SemVal const &rhs)
{
    downCast<CharClass>(*lhs).d_set += downCast<CharClass>(rhs).d_set;

    return lhs;
}
