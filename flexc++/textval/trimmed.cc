#include "textval.ih"

spSemVal TextVal::trimmed(string const &str)
{
    spSemVal ret(new TextVal(String::trim(str)));
    return ret;
}
