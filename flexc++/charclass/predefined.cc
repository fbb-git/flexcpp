#include "charclass.ih"

spSemVal CharClass::predefined(string const &predef)
{
    spSemVal ret(new CharClass(CharRange::predefined(predef)));
    return ret;
}
