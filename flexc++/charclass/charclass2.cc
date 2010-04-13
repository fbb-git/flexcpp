#include "charclass.ih"

CharClass::CharClass(string const &str)
:
    d_last(1, str[0])
{}
