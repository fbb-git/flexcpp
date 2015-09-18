#include "charclass.hh"

string CharClass::chars(string const &matched)
{
    string ret(string(1, 'c') + matched);

    return ret;
}
