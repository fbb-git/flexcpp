#include "charclass.ih"

CharClass CharClass::negate(CharClass &left, CharClass const &right)
{
    concatenate(left, right);
    CharClass ret(negate(left));

    return ret;
}
