#include "charclass.ih"

spSemVal CharClass::predefined(string const &predef)
{
    spSemVal ret(new CharClass(Range::predefined(predef)));
    return ret;
}
