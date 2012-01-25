#include "charclass.ih"

CharClass CharClass::escape(string const &match)
{
    CharClass ret(String::unescape(match));
    return ret;
}
