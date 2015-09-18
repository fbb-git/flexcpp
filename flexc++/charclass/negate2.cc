#include "charclass.hh"

void CharClass::negate(vector<string> const &strings)
{
    append(strings);
    negate();
}
