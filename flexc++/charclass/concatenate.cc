#include "charclass.ih"

spSemVal &CharClass::concatenate(spSemVal &left, SemVal const &right)
{
    CharClass &lhs = downCast<CharClass>(*left);
    CharClass const &rhs = downCast<CharClass>(right);

    lhs.d_chars += rhs.d_chars;

    return left;    
}
