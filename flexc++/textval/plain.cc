#include "textval.ih"

spSemVal TextVal::plain(string const &str)
{
    spSemVal ret(new TextVal(str));
    return ret;
}
