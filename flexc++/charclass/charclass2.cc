#include "charclass.ih"

CharClass::CharClass(string const &str)
:
    d_set(str.begin(), str.begin() + 1)
//    d_last(1, str[0])
{}
