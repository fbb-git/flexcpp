#include "charclass.ih"

CharClass::CharClass(set<char> const &charSet)
:
    d_set(charSet)
{}
