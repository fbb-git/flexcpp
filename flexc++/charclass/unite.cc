#include "charclass.ih"

spSemVal &CharClass::unite(spSemVal &lhs, SemVal const &rhs)
{
    downCast<CharClass>(*lhs).d_chars += downCast<CharClass>(rhs).d_chars;

    return lhs;
}
