#include "charclass.ih"

CharClass CharClass::elements(string const &chars, size_t skip)
{
    CharClass ret(String::unescape(skip == 0 ? chars : chars.substr(skip)));
    return ret;
}
