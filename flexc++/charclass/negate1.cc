#include "charclass.ih"

CharClass CharClass::negate() const
{
    CharClass ret( CharRange::negate(set()) );
    return ret;
}
