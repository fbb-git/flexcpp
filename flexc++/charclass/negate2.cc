#include "charclass.ih"

void CharClass::negate(vector<string> const &strings)
{
    append(strings);
    negate();
}
