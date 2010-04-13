#include "charclass.ih"

spSemVal CharClass::escape(string const &match)
{
    spSemVal ret(new CharClass(String::unescape(match)));
    return ret;
}
