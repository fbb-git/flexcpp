#include "charclass.ih"

spSemVal CharClass::plain(char ch)
{
    spSemVal ret(new CharClass(ch));
    return ret;
}
