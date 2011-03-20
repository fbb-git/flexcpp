#include "charclass.ih"

CharClass::CharClass(char ch)
:
    d_set(&ch, &ch + 1)
//    d_last(1, ch)
{}
