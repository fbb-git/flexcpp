#include "charclass.ih"

string CharClass::str() const
{
    string ret;

    copy(d_set.begin(), d_set.end(), inserter(ret, ret.end()));

    return ret;
}
