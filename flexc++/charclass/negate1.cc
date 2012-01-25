#include "charclass.ih"

CharClass CharClass::negate(CharClass const &charClass)
{
    CharClass ret( CharRange::negate(charClass.set()) );
    return ret;
}
