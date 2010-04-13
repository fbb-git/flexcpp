#include "textval.ih"

spSemVal &TextVal::cat(spSemVal &lhs, spSemVal const &rhs)
{
    downCast<TextVal>(*lhs).d_text += downCast<TextVal>(*rhs).d_text;
    return lhs;
}
