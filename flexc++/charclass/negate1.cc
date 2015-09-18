#include "charclass.hh"

void CharClass::negate()
{
    d_str = CharRange::negate(str());
    d_state = NEGATED;
}
