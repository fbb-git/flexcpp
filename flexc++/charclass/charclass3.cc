#include "charclass.ih"

CharClass::CharClass(string const &chars, size_t skip)
:
    d_str(skip == 0 ? chars : chars.substr(skip))
{}
