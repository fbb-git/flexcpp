#include "charclass.ih"

CharClass::CharClass(string const &chars, size_t skip)
:
    d_str(skip == 0 ? chars : chars.substr(skip)),
    d_type(1, {0, CHAR})
{}
