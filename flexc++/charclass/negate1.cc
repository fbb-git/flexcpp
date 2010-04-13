#include "charclass.ih"

spSemVal CharClass::negate(spSemVal const &charClass)
{
    spSemVal ret(
                    new CharClass(Range::negate(
                        downCast<CharClass>(*charClass).d_set)
                    )
                );
    return ret;
}
