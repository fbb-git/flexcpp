#include "charclass.ih"

string CharClass::predefined(string const &predef)
{
    string ret(string(1, 'p') + CharRange::predefined(predef));

    return ret;
}
