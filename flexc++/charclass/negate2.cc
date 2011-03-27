#include "charclass.ih"

spSemVal CharClass::negate(spSemVal &left, SemVal const &right)
{
    concatenate(left, right);
    spSemVal ret(negate(left));

    return ret;
}
